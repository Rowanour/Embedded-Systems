#include <stdio.h>
#include <string.h>
struct o
{
    int id;
    char name[20];
};

struct o update(struct o item)
{
    printf("Enter new ID: ");
    scanf("%d", &item.id);

    printf("Enter new name: ");
    scanf("%s", item.name);

    return item;
}

int main()
{
    struct o item;
    strcpy(item.name, "undefined");
    item.id = 0;

    printf("Before update:\n");
    printf("ID: %d\n", item.id);
    printf("Name: %s\n", item.name);

    // Call the update function to modify the structure
    item = update(item);

    printf("After update:\n");
    printf("ID: %d\n", item.id);
    printf("Name: %s\n", item.name);

    return 0;
}

