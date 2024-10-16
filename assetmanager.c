
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ASSETS 100
#define MAX_NAME_LENGTH 50

// Structure to represent an asset
typedef struct {
    char name[MAX_NAME_LENGTH];
    double value;
    int riskRating; // 1-10 where 10 is highest risk
} Asset;

// Function prototypes
void addAsset(Asset assets[], int *assetCount);
void listAssets(Asset assets[], int assetCount);
double totalAssetValue(Asset assets[], int assetCount);

int main() {
    Asset assets[MAX_ASSETS];
    int assetCount = 0;
    int choice;

    do {
        // Display menu options
        printf("\n--- Insurance Asset Manager ---\n");
        printf("1. Add an Asset\n");
        printf("2. List Assets\n");
        printf("3. Calculate Total Asset Value\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAsset(assets, &assetCount);
                break;
            case 2:
                listAssets(assets, assetCount);
                break;
            case 3:
                printf("Total Asset Value: £%.2f\n", totalAssetValue(assets, assetCount));
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}

// Function to add a new asset
void addAsset(Asset assets[], int *assetCount) {
    if (*assetCount >= MAX_ASSETS) {
        printf("Asset list is full! Cannot add more assets.\n");
        return;
    }

    Asset newAsset;

    // Get asset details
    printf("Enter asset name: ");
    getchar(); // To clear the buffer from previous input
    fgets(newAsset.name, MAX_NAME_LENGTH, stdin);
    newAsset.name[strcspn(newAsset.name, "\n")] = '\0';  // Remove newline character

    printf("Enter asset value (in £): ");
    scanf("%lf", &newAsset.value);

    printf("Enter asset risk rating (1-10): ");
    scanf("%d", &newAsset.riskRating);

    // Add new asset to the list
    assets[*assetCount] = newAsset;
    (*assetCount)++;

    printf("Asset added successfully!\n");
}

// Function to list all assets
void listAssets(Asset assets[], int assetCount) {
    if (assetCount == 0) {
        printf("No assets available!\n");
        return;
    }

    printf("\n--- Asset List ---\n");
    for (int i = 0; i < assetCount; i++) {
        printf("Asset %d:\n", i + 1);
        printf("Name: %s\n", assets[i].name);
        printf("Value: £%.2f\n", assets[i].value);
        printf("Risk Rating: %d\n", assets[i].riskRating);
        printf("\n");
    }
}

// Function to calculate total asset value
double totalAssetValue(Asset assets[], int assetCount) {
    double totalValue = 0.0;

    for (int i = 0; i < assetCount; i++) {
        totalValue += assets[i].value;
    }

    return totalValue;
}
