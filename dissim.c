
void disim(void);
static float dsim_matrix[max][max];
int ds()
{
	standard();
	disim();
}
void disim(void)
{
	float distance;
	printf("Dissimilarity matrix is%f\n",distance);	
	for(int i=0;i<data_set_count;i++){
		for(int j=0;j<=i;j++){
			distance=0;
			for(int k=0;k<2;k++){
				distance+=pow((std_matrix[i][k]-std_matrix[j][k]),2);
				 //printf("distance%f\tstd_matrix[i][k] %f\tstd_matrix[j][k]%f\n",distance,std_matrix[i][k],std_matrix[j][k]);
			}
			distance=sqrt(distance);
			dsim_matrix[i][j]=distance;
			dsim_matrix[j][i]=distance;
			printf("%.4f\t",dsim_matrix[i][j]);
			
		}
		printf("\n\n");
	}

}

















