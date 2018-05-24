
int std(float data_set[max][size],float mean[size],float std_dev[size]);
int data_set_count;
float data_set[max][size],std_matrix[max][size];
int standard()
{
	FILE *fp;
	fp=fopen("data.txt","r");
	char ch,str[15];
	int count1=0,feature=0,k=2;
	static float std_dev[size],mean[size];

	
	if(fp==NULL){
		printf("openig error\n\n");	
		exit(0);
	}

	ch=fgetc(fp);
	data_set_count=0;
	while(1)
	{
		if(ch==' '||ch=='\n'||ch==','){
			str[count1]='\0';
			data_set[data_set_count][feature]=atoi(str);
			//printf("\t%d",data_set[data_set_count][feature]);
			data_set_count++;
			strcpy(str," ");
			count1=0;			
			if(ch==','){
				feature=1;
				data_set_count--;
				ch=fgetc(fp);
	 		}
			else
				feature=0;
			
		}		
		else if(ch==EOF)
			break;
			str[count1]=ch;
			count1++;
			ch=fgetc(fp);
			
	}

	printf("\nData matrix is\n\n");
	for(int i=0;i<data_set_count;i++)
	{
		printf("%d::",i);
		for(int j=0;j<2;j++){
			printf("\t%.3f\t",data_set[i][j]);
		}
		printf("\n");
	}
	//to find mean values
	for(int i=0;i<k;i++){
		for(int j=0;j<data_set_count;j++){
			mean[i]+=data_set[i][j];
		}
		mean[i]/=data_set_count;
	}

	for(int i=0;i<k;i++){
		for(int j=0;j<data_set_count;j++){
			std_dev[i]+=pow((data_set[i][j]-mean[i]),2)/data_set_count;
		}
		std_dev[i]=sqrt(std_dev[i]);
	}
	
	std(data_set,mean,std_dev);
fclose(fp);
return 0;
}
int std(float data_set[max][size],float mean[size],float std_dev[size])
{
	
	float z;
	printf("Standardized matrix is\n\n");
	for(int i=0;i<data_set_count;i++){
		z=(float)(data_set[i][0]-mean[0])/std_dev[0];
		std_matrix[i][0]=z;
		z=(float)(data_set[i][0]-mean[1])/std_dev[1];
		std_matrix[i][1]=z;
		printf("%d::\t%.3f\t%.3f\n",i,std_matrix[i][0],std_matrix[i][1]);					
	}
return 0;
}



















