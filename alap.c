#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_args(int argc)
{
    if (argc < 2)
    {
        printf("alap v0.1.0,\n\n");

        printf("Usage: alap <template_id> [option]\n\n");

        printf("Available options:\n\n");
        printf("-h, --help\t\t  show this help\n");
        printf("-v, --version\t\t  version info\n");
        printf("--stdout\t\t  don't create souce file, print result to stdout\n\n");

        printf("Available options:\n\n");
        printf("* c \t\t\t- C source code [main.c]\n");
        printf("* java \t\t\t- Java source code [Main.java]\n");
        printf("* sh \t\t\t- Bash source code [main.sh]\n");
    }
}

int check_file(char *lang)
{

    if (strcmp(lang, "c") == 0)
    {
        FILE *c = fopen("main.c", "r");
        if (c != NULL)
        {
            fprintf(stderr, "Error: the file 'main.c' already exists\n");
            return 1;
        }
    }
    else if (strcmp(lang, "java") == 0)
    {
        FILE *java = fopen("Main.java", "r");
        if (java != NULL)
        {
            fprintf(stderr, "Error: the file 'Main.java' already exists\n");
            return 1;
        }
    }
    else if (strcmp(lang, "sh") == 0)
    {
        FILE *sh = fopen("main.sh", "r");
        if (sh != NULL)
        {
            fprintf(stderr, "Error: the file 'main.sh' already exists\n");
            return 1;
        }
    }

    return 0;
}

int check_option(char *option)
{
    if (strcmp(option, "-h") == 0 || strcmp(option, "--help") == 0)
    {
        check_args(1);
    }
    else if (strcmp(option, "-v") == 0 || strcmp(option, "--version") == 0)
    {
        printf("alap v0.1.0\n");
    }
    else if (strcmp(option, "--stdout") == 0)
    {
        return 1;
    }
    return 0;
}
void c_lang()
{
    FILE *c = fopen("main.c", "w");

    fprintf(c, "#include <stdio.h>\n\n");
    fprintf(c, "int main()\n");
    fprintf(c, "{\n");
    fprintf(c, "\tprintf(\"hello\\n\");\n\n");
    fprintf(c, "\treturn 0;\n");
    fprintf(c, "}\n");

    fclose(c);
}

void java_lang()
{
    FILE *java = fopen("Main.java", "w");

    fprintf(java, "class Main{\n");
    fprintf(java, "\tpublic static void main(String[] args) {\n");
    fprintf(java, "\t\tSystem.out.println(\"Hello, World!\\n\");\n");
    fprintf(java, "\t}\n");
    fprintf(java, "}\n");

    fclose(java);
}

void sh_lang()
{
    FILE *sh = fopen("main.sh", "w");

    fprintf(sh, "#!/bin/bash\n");
    fprintf(sh, "#Usage: Hello World Bash Shell Script Using Variables\n");
    fprintf(sh, "#----------------------------------------------------\n\n");
    fprintf(sh, "echo \"$var\"\n");

    fclose(sh);
}

void c_print()
{
    printf("#include <stdio.h>\n\n");
    printf("int main()\n");
    printf("{\n");
    printf("\tprintf(\"hello\\n\");\n\n");
    printf("\treturn 0;\n");
    printf("}\n");
}

void java_print()
{
    printf("class Main{\n");
    printf("\tpublic static void main(String[] args) {\n");
    printf("\t\tSystem.out.println(\"Hello, World!\\n\");\n");
    printf("\t}\n");
    printf("}\n");
}

void sh_print()
{
    printf("#!/bin/bash\n");
    printf("#Usage: Hello World Bash Shell Script Using Variables\n");
    printf("#----------------------------------------------------\n\n");
    printf("echo \"$var\"\n");
}

int write_file(char *lang)
{
    if (check_file(lang) && !check_option(lang))
    {
        return 1;
    }
    if (strcmp(lang, "c") == 0)
    {
        c_lang();
    }
    else if (strcmp(lang, "java") == 0)
    {
        java_lang();
    }
    else if (strcmp(lang, "sh") == 0)
    {
        sh_lang();
    }
    return 0;
}

void print_out(char *lang)
{
    if (strcmp(lang, "c") == 0)
    {
        c_print();
    }
    else if (strcmp(lang, "java") == 0)
    {
        java_print();
    }
    else if (strcmp(lang, "sh") == 0)
    {
        sh_print();
    }
}

int main(int argc, char *argv[])
{
    check_args(argc);

    char *lang = argv[1];

    if (check_option(argv[argc - 1]))
    {
        print_out(lang);
    }
    else
    {
        write_file(lang);
    }

    return 0;
}