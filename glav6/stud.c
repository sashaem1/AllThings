#include <stdio.h>
#include <stdlib.h>

struct Student
{
  int Groupe;     
  char Name[20]; 
  float Raiting;
  int Iselder;   
} Student1;

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
    s->Name[i] = '\0';
    fscanf(f, "%f", &s->Raiting);
    fscanf(f, "%d", &s->Iselder);

}
void Output1(FILE *f, struct Student *s)
{
    fprintf(f, "%d ", s->Groupe);
    int i = 0;
    while (s->Name[i] != '\0')
    {
        fprintf(f, "%c", s->Name[i]);
        i++;
    }
    fprintf(f, " %f ", s->Raiting);
    fprintf(f, "%d", s->Iselder);

}


int main()
{
    struct Student *Student;
    Student = &Student1;
    FILE *IN;
    IN = fopen("in.txt", "r");
    if (IN == NULL)
    {
    printf("File ne otrilsya\n");
    return -1;
    }
    Input1(IN, Student);
    fclose(IN);
    FILE *OUT;
    OUT = fopen("out.txt", "w");
    if (OUT == NULL)
    {
    printf("File ne otrilsya\n");
    return -1;
    }
    Output1(OUT, Student);
    fclose(OUT);
    return 0; 
}