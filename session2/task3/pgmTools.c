#include <stdlib.h>
#include <stdio.h>

int getUserInput(unsigned char* message);
void displayMenu(void);
unsigned char** allocateArray(int height, int width);
unsigned char** readImageFile(unsigned char* fn, int* height, int* width);
void printImage(unsigned char** image, int height, int width);
void invertImage(unsigned char** image, int height, int width);
void freeImage(unsigned char** image, int height);

int main(int argc, unsigned char** argv)
{
	if(argc!=2)
	{
		printf("Usage: ./pgmTools image_path\n");
		return 1;
	}

	int height,width;
	unsigned char** image;
	image=readImageFile(argv[1],&height,&width);

	int c;
	while(1)
	{
		c=-1;
		displayMenu();
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
				invertImage(image,height,width);
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				freeImage(image,height);
				return 0;
			default:
				printf("Bad choice\n");
				break;
		}
	}
	freeImage(image,height);
}

int getUserInput(unsigned char* message)
{
	unsigned char buffer[100];
	int choice;
	printf("%s: ",message);
	fgets(buffer,100,stdin);
	int check=sscanf(buffer,"%d",&choice);
	if(check!=1)
	{
		return -1;
	}
	return choice;
}

void displayMenu(void)
{
	printf("1 - View PGM Image\n");
	printf("2 - Invert Image\n");
	printf("3 - Rotate Image\n");
	printf("4 - Scale Image\n");
	printf("5 - quit\n");
}

unsigned char** allocateArray(int height, int width)
{
	unsigned char** array=calloc(height,sizeof(unsigned char*));
	for(int i=0;i<height;i++)
	{
		array[i]=calloc(width,sizeof(unsigned char));
	}
	return array;
}

unsigned char** readImageFile(unsigned char* fn, int* height, int* width)
{
	unsigned char temp[10];
	int h,w;
	FILE* f=fopen(fn,"r");
	fscanf(f,"%s ",temp);
	fscanf(f,"%d %d",&h,&w);
	fscanf(f,"%s ",temp);
	unsigned char** p=allocateArray(h,w);
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			fscanf(f,"%hhd",&p[i][j]); //not sure if this should be %hhu since p[i][j] is a uint8
		}
	}
	*height=h;
	*width=w;
	return p;
}

void printImage(unsigned char** image, int height, int width)
{
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			printf("%d%s",image[i][j],(image[i][j]<100)?(image[i][j]<10)?"   ":"  ":" ");
			//these ternary operators are for displaying the image properly
			//so that "123", "23" and "3" are all aligned by making them "123", " 23" and "  3"
		}
		printf("\n");
	}
}

void invertImage(unsigned char** image, int height, int width)
{
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			image[i][j]=255-image[i][j];
		}
	}
}

void freeImage(unsigned char** image, int height)
{
	for(int i=0;i<height;i++)
	{
		free(image[i]);
	}
	free(image);
}