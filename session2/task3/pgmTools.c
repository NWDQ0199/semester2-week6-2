#include <stdlib.h>
#include <stdio.h>

int getUserInput(unsigned char *message);
void menu(void);
unsigned char **allocateArray(int height, int width);
unsigned char **read(unsigned char *fn, int *a, int *b);
void printImage(unsigned char **p, int a, int b);

int main(int argc, unsigned char **argv)
{
	if(argc!=2)
	{
		printf("Usage: ./pgmTools image_path\n");
		return 1;
	}

	int height,width;
	unsigned char **image;
	image=readImageFile(argv[1],&height,&width);

	int c;
	while(1)
	{
		c=-1;
		menu();
		while(c<1)
		{
			c=getUserInput("Enter choice");
		}

		switch (c)
		{
			case 1:
				printImage(image,height,width);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				return 0;
			default:
				printf("Bad choice\n");
				break;
		}
	}
	for(int i=0;i<height;i++)
	{
		free(i[i]);
	}
}

int getUserInput(unsigned char *message)
{
	unsigned char buffer[100];
	int choice;
	printf("%s: ",message);
	fgets(buffer,100,stdin);
	int check=sscanf(buffer,"%d",&choice);
	if(!check)
	{
		return -1;
	}
	return choice;
}

void menu(void)
{
	printf("1 - View PGM Image\n");
	printf("2 - Invert Image\n");
	printf("3 - Rotate Image\n");
	printf("4 - Scale Image\n");
	printf("5 - quit\n");
}

unsigned char **allocateArray(int height, int width)
{
	unsigned char** array=calloc(height,sizeof(unsigned char*));
	for(int i=0;i<height;i++)
	{
		array[i]=calloc(width,sizeof(unsigned char));
	}
	return array;
}

unsigned char **readImageFile(unsigned char *fn, int *height, int *width)
{
	unsigned char temp[10];
	int h,w;
	FILE *f=fopen(fn,"r");
	fscanf(f,"%s ",temp);
	fscanf(f,"%d %d",&h,&w);
	fscanf(f,"%s ",temp);
	unsigned char **p=allocateArray(h,w);
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			fscanf(f,"%hhd",&p[i][j]);
		}
	}
	*height=h;
	*width=w;
	return p;
}

void printImage(unsigned char **p, int a, int b)
{
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
		{
			printf("%d%s",p[i][j],(p[i][j]<100)?(p[i][j]<10)?"\t ":"\t":" ");
		}
		printf("\n");
	}
}