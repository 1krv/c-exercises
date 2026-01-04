#include <stdio.h>
#include <string.h>

typedef struct student {
    int id;
    char name[64];
    float avg_grade;
    int active; // 1 = active; 0 = deleted.
} student;

void populate_db(FILE *fp) {
    student s1, s2, s3;

    s1.id = 1;
    memset(s1.name, 0, sizeof(s1.name));
    strcpy(s1.name, "John Wilkins");
    s1.avg_grade = 19;
    s1.active = 1;

    s2.id = 2;
    memset(s2.name, 0, sizeof(s2.name));
    strcpy(s2.name, "Alyssa Lancini");
    s2.avg_grade = 30;
    s2.active = 1;

    s3.id = 3;
    memset(s3.name, 0, sizeof(s3.name));
    strcpy(s3.name, "Andrew Strong");
    s3.avg_grade = 24;
    s3.active = 1;

    fwrite(&s1, sizeof(student), 1, fp);
    fwrite(&s2, sizeof(student), 1, fp);
    fwrite(&s3, sizeof(student), 1, fp);

    fseek(fp, 0L, SEEK_SET);
}

long get_filesize(FILE *fp) {
    long filesize;
    fseek(fp, 0L, SEEK_END);
    filesize = ftell(fp);
    rewind(fp);

    return filesize;
}

void add_student(FILE *fp, char *name, float avg_grade) {
    student s;

    s.id = (int)((get_filesize(fp) / sizeof(student)) + 1);
    memset(s.name, 0, sizeof(s.name));
    strncpy(s.name, name, sizeof(s.name) - 1);
    s.avg_grade = avg_grade;
    s.active = 1;

    fseek(fp, 0L, SEEK_END);
    fwrite(&s, sizeof(student), 1, fp);
    rewind(fp);
}

void delete_student(FILE *fp, int id) {
    student s;

    long max_id = get_filesize(fp) / sizeof(student);
    if (id < 1 || id > max_id) {
        printf("Error: Unable to find student ID %d\n", id);
        return;
    }

    fseek(fp, sizeof(student) * (id - 1), SEEK_SET);
    fread(&s, sizeof(student), 1, fp);

    if (s.active == 0) {
        printf("Student ID %d has been already deleted.\n", id);
        return;
    }

    s.active = 0;

    fseek(fp, sizeof(student) * (id - 1), SEEK_SET);
    fwrite(&s, sizeof(student), 1 , fp);
    rewind(fp);

    printf("Student ID %d has been deleted.\n", id);
}

void update_avg_grade(FILE *fp, int id, float new_avg_grade) {
    student s;

    long max_id = get_filesize(fp) / sizeof(student);
    if (id < 1 || id > max_id) {
        printf("Error: Unable to find student ID %d\n", id);
        return;
    }

    fseek(fp, sizeof(student) * (id - 1), SEEK_SET);
    fread(&s, sizeof(student), 1, fp);

    if (s.active == 0) {
        printf("Error: Student ID %d is deleted.\n", id);
        return;
    }

    s.avg_grade = new_avg_grade;

    fseek(fp, sizeof(student) * (id - 1), SEEK_SET);
    fwrite(&s, sizeof(student), 1, fp);
    rewind(fp);
}

void print_student(FILE *fp, int id) {
    student s;

    long max_id = get_filesize(fp) / sizeof(student);
    if (id < 1 || id > max_id) {
        printf("Error: Unable to find student ID %d\n", id);
        return;
    }

    fseek(fp, sizeof(student) * (id - 1), SEEK_SET);
    fread(&s, sizeof(student), 1, fp);
    rewind(fp);

    if (s.active == 1) {
        printf("======================================\n");
        printf("ID \t%d\nNAME\t%s\nAVG GRADE\t%.2f\n", s.id, s.name, s.avg_grade);
    } else {
        printf("Error: The requested student ID %d has been deleted.\n'", id);
    }
}

/* Print all the records from the given binary file. */
void print_table(FILE *fp) {
    student s;
    long n_records;
    long file_size;

    file_size = get_filesize(fp);
    n_records = file_size / sizeof(student);

    printf("FILE> db.dat\n");
    if (n_records == 0) {
        printf("There are no records in the table.\n");
    } else {
        printf("There are %ld records in the table. (File size: %ld bytes)\n",
            n_records, file_size);
        printf("======================================\n");
    }

    while (fread(&s, sizeof(student), 1, fp) == 1) {
        if (s.active == 1) {
            printf("ID %d | %s \t| %.2f\n",
                s.id, s.name, s.avg_grade);
        }
    }

    fseek(fp, 0L, SEEK_SET);
}

int main(void) {
    FILE *fp;

    fp = fopen("db.dat", "rb+");
    if (fp == NULL) {
        printf("Missing db.dat file. Creating new database...\n");
        fp = fopen("db.dat", "wb+");

        if (fp == NULL) {
            perror("Unable to create the file.");
            return 1;
        }

        populate_db(fp);
    }

    print_table(fp);
    delete_student(fp, 2);
    print_student(fp, 2);
    print_table(fp);

    fclose(fp);
    return 0;
}
