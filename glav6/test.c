#include <conio.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


struct Student
{
  int Groupe;     
  char Name[20]; 
  float Raiting;
  int Iselder;   
}Student1;

void Input1(FILE *f, struct Student *s)
{
    fscanf(f, "%d", &s->Groupe);
    fscanf(f, "%c", &s->Name);
    int i = 0;
    char ch;
    while ((ch = getc(f)) != ' ')
    {
        s->Name[i] = ch;
        i++;
    }
    s->Name[i] = ' ';
    fscanf(f, "%f", &s->Raiting);
    fscanf(f, "%d", &s->Iselder);

}
void Output1(FILE *f, struct Student *s)
{
    fprintf(f, "%d ", s->Groupe);
    int i = 0;
    do
    {
        fprintf(f, "%c", s->Name[i]);
        i++;
    }while (s->Name[i] != ' ');
    fprintf(f, " %f ", s->Raiting);
    fprintf(f, "%d \n", s->Iselder);

}


int main()
{
    struct Student *Student;
    // Student = &Student1;
    int n = 2;
    Student = (struct Student*)malloc(n*sizeof(struct Student));
    FILE *IN;
    IN = fopen("in.txt", "r");
    if (IN == NULL)
    {
    printf("File ne otrilsya\n");
    return -1;
    }
    Input1(IN, Student);
    Input1(IN, Student+1);
    n++;
    Student = (struct Student*)realloc(Student, n*sizeof(struct Student));
    Input1(IN, Student+2);
    fclose(IN);
    FILE *OUT;
    OUT = fopen("out.txt", "w");
    if (OUT == NULL)
    {
    printf("File ne otrilsya\n");
    return -1;
    }
    Output1(OUT, Student);
    Output1(OUT, Student+1);
    Output1(OUT, Student+2);
    fclose(OUT);
    return 0; 
}