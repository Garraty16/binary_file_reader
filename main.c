#include<stdio.h>

	/* Our structure */
	struct rec
	{
		int num;
		char str[255];
		float f;
	};

	int main(int argc, char *argv[])
	{
		FILE *ptr_myfile;
		struct rec my_record;

		ptr_myfile=fopen(argv[1],"rb");
		if (!ptr_myfile)
		{
			printf("Unable to open file!");
			return 1;
		}
		while (fread(&my_record,sizeof(struct rec),1,ptr_myfile) == 1)
		{
			
			printf("%d\t",my_record.num);
			printf("%s\t",my_record.str);
			printf("%f\t\n",my_record.f);
		}
		fclose(ptr_myfile);
		return 0;
	}