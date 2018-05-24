
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#define max 200
#define size 5
#include"std_data.c"
#include"dissim.c"
static float cluster_setx[size][max],cluster_sety[size][max];
int find_mean(float mean_set[size][size])
{
	static float meanx,meany,count;
	for(int i=0;i<2;i++){
	 	for(int j=0;j<data_set_count;j++){
			if(cluster_setx[i][j]!=0&&cluster_sety[i][j]!=0){
				meanx+=cluster_setx[i][j];
				meany+=cluster_sety[i][j];
				count++;
			}	
		}
		mean_set[i][0]=meanx/count;
		mean_set[i][1]=meany/count;	
        }
return 0;//(mean_set);
}

int cluster(int k,float mean_set[size][size])
{
	
	static float distance[max],mean_set2[size][size];
	while(1){

		//printf("in cluster\n");
		for(int i=0;i<k;i++){
			for(int j=0;j<data_set_count;j++){
				cluster_setx[i][j]=0;
				cluster_sety[i][j]=0;
			}
		}
		for(int i=0;i<data_set_count;i++){
			for(int j=0;j<k;j++){
				for(int l=0;l<k;l++){
					distance[j]+=pow((mean_set[j][l]-data_set[i][l]),2);
				}
				distance[j]=sqrt(distance[j]);
			}
			if(distance[0]<distance[1]){
				cluster_setx[0][i]=data_set[i][0];
				cluster_sety[0][i]=data_set[i][1];
			}
			else{
				cluster_setx[1][i]=data_set[i][0];
				cluster_sety[1][i]=data_set[i][1];
			}
			
		}		 
		  mean_set2[0][0]=mean_set[0][0];
		  mean_set2[0][1]=mean_set[0][1];
		  mean_set2[1][0]=mean_set[1][0];
		  mean_set2[1][1]=mean_set[1][1];
		  find_mean(mean_set);
if(mean_set2[0][0]==mean_set[0][0]&&mean_set2[0][1]==mean_set[0][1]&&mean_set2[1][0]==mean_set[1][0]&&mean_set2[1][1]==mean_set[1][1]){
			printf("final mean values are\n");
			printf("\n\n(%f,%f)\n",mean_set[0][0],mean_set[0][1]);
			printf("\n(%f,%f)\n\n",mean_set[1][0],mean_set[1][1]);
			break;
		    }
	}
return 0;//(cluster_set);
}

int main()
{
	 
	float mean_set[size][size];
	int random_index,k=2;
 	ds();
	printf("k=%d\ninitial randomly chooses mean values are\n",k);
	srand(time(NULL));	
	for(int i=0;i<k;i++)
	{
	 	random_index=(int)rand() % (data_set_count+1-0)+0;//random no between no. of dataset and 0
	 	mean_set[i][0]=data_set[random_index][0];
	 	mean_set[i][1]=data_set[random_index][1];
		printf("%f\t%f\n",mean_set[i][0],mean_set[i][1]);	
	}
	
	cluster(k,mean_set);//k=no of feature/dimension
	printf("\nCluster sets are:\n\n");
	for(int i=0;i<k;i++){
			for(int j=0;j<data_set_count;j++){
				if(cluster_setx[i][j]!=0||cluster_sety[i][j]!=0){
					printf("(%f  ",cluster_setx[i][j]);
					printf(",%f)\t",cluster_sety[i][j]);
				}
			}
			printf("\n\n");
		}
	
return 0;	
}
