#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int bus_slot = 5, car_slot = 5, bike_slot = 20, auto_slot = 15;
int earings = 0, bus_count = 0, car_count = 0, bike_count = 0, auto_count = 0;
int index1 = 0, index2 = 0, index3 = 0;
struct customer
{
    char customerName[10][20], date[10][13];
    int vehicleNumber[10];
} data;
void print_receipt(int fees)
{
    printf("\n\t\t\t\t\t\t\t\t  Here you receipt!\n");
    printf("\t\t\t\t\t\t\t***************************************\n");
    printf("\t\t\t\t\t\t\t\t  Name: %s\n", data.customerName[index2]);
    printf("\t\t\t\t\t\t\t\t  Vehicle numebr: %d\n", data.vehicleNumber[index1]);
    printf("\t\t\t\t\t\t\t\t  Date: %s\n", data.date[index3]);
    printf("\t\t\t\t\t\t\t\t  Paid Ammount : %d\n", fees);
    printf("\t\t\t\t\t\t\t***************************************\n");
}
void bus_park()
{
    int fees;
    printf("\n Your Parking Slot Number : %d \n",index1+1);
    printf("***********************************\n");
    printf("Enter your name: ");
    fflush(stdin);
    gets(data.customerName[index2]);
    printf("Enter vehicle number: ");
    scanf("%d", &data.vehicleNumber[index1]);
    printf("Enter today's date: ");
    fflush(stdin);
    gets(data.date[index3]);
repeat:
    printf("Please enter fees: ");
    scanf("%d", &fees);
    if (fees < 200 || fees > 200)
    {
        printf("Please enter valid amount ");
        goto repeat;
    }
    else
    {
        earings = earings + fees;
        printf("Your payment is successfully done\n");
    }
    print_receipt(fees);
    index1++;
    index2++;
    index3++;
    bus_count++;
}
void car_park()
{
    int fees;
    printf("\n Your Parking Slot Number : %d \n",index1+1);
    printf("***********************************\n");
    printf("Enter your name: ");
    fflush(stdin);
    gets(data.customerName[index2]);
    printf("Enter vehicle number: ");
    scanf("%d", &data.vehicleNumber[index1]);
    printf("Enter today's date: ");
    fflush(stdin);
    gets(data.date[index3]);
repeat:
    printf("Enter parking fees: ");
    scanf("%d", &fees);
    if (fees < 150 || fees > 150)
    {
        printf("Please enter valid amount ");
        goto repeat;
    }
    else
    {
        earings = earings + fees;
        printf("Your payment is successfully done\n");
    }
    print_receipt(fees);
    index1++;
    index2++;
    index3++;
    car_count++;
}
void bike_park()
{
    int fees;
    printf("\n Your Parking Slot Number : %d \n",index1+1);
    printf("***********************************\n");
    printf("Enter your name: ");
    fflush(stdin);
    gets(data.customerName[index2]);
    printf("Enter vehicle number: ");
    scanf("%d", &data.vehicleNumber[index1]);
    printf("Enter today's date: ");
    fflush(stdin);
    gets(data.date[index3]);
repeat:
    printf("Enter parking fees: ");
    scanf("%d", &fees);
    if (fees < 50 || fees > 50)
    {
        printf("Please enter valid amount ");
        goto repeat;
    }
    else
    {
        earings = earings + fees;
        printf("Your payment is successfully done\n");
    }
    print_receipt(fees);
    index1++;
    index2++;
    index3++;
    bike_count++;
}
void auto_park()
{
    int fees;
    printf("\n Your Parking Slot Number : %d \n",index1+1);
    printf("***********************************\n");
    printf("Enter your name: ");
    fflush(stdin);
    gets(data.customerName[index2]);
    printf("Enter vehicle number: ");
    scanf("%d", &data.vehicleNumber[index1]);
    printf("Enter today's date: ");
    fflush(stdin);
    gets(data.date[index3]);
repeat:
    printf("Enter parking fees: ");
    scanf("%d", &fees);
    if (fees < 100 || fees > 100)
    {
        printf("Please enter valid amount ");
        goto repeat;
    }
    else
    {
        earings = earings + fees;
        printf("Your payment is successfully done\n");
    }
    print_receipt(fees);
    index1++;
    index2++;
    index3++;
    auto_count++;
}
void park_vehicle()
{
    int choose;
again:
    printf("\n1.Bus                     2.Car\n");
    printf("3.Bike                    4.Auto\n");
    printf("Which vehicle you want to park: ");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        if (bus_slot == 0)
        {
            printf("\nSorry! Bus parking slot is not available\n");
        }
        else
        {
            bus_park();
            bus_slot--;
        }
        break;
    case 2:
        if (car_slot == 0)
        {
            printf("\nSorry! Car parking slot is not available\n");
        }
        else
        {
            car_park();
            car_slot--;
        }
        break;
    case 3:
        if (bike_slot == 0)
        {
            printf("\nSorry! Bike parking slot is not available\n");
        }
        else
        {
            bike_park();
            bike_slot--;
        }
        break;
    case 4:
        if (auto_slot == 0)
        {
            printf("\nSorry! Auto parking slot is not available\n");
        }
        else
        {
            auto_park();
            auto_slot--;
        }
        break;
    default:
        printf("Invalid number try again\n");
        goto again;
    }
}
void check_out()
{
    int choice;
again2:
    while(1)
    {
        printf("What Kind of vehicle you need to check out\n");
        printf("1. Bus\n2. Car\n3. Bike\n4. Auto\n5. Exit\n");
        printf("Enter Your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            bus_checkout();
            return second();
            break;
        case 2:
            car_checkout();
            return second();
            break;
        case 3:
            bike_checkout();
            return second();
            break;
        case 4:
            auto_checkout();
            return second();
            break;
        case 5:
            return second();
            break;
        default:
            printf("You enter wrong choice\n");
            goto again2;
        }
    }
}
void bus_checkout()
{
    int value,ind;
    printf("Enter your bus slot number : ");
    scanf("%d",&value);
    ind=value-1;
    strcpy(data.customerName[ind],"0");
    data.vehicleNumber[ind]=0;
    strcpy(data.date[ind],"0");
}
void car_checkout()
{
    int value,ind;
    printf("Enter your Car slot number : ");
    scanf("%d",&value);
    ind=value-1;
    strcpy(data.customerName[ind],"0");
    data.vehicleNumber[ind]=0;
    strcpy(data.date[ind],"0");
}
void bike_checkout()
{
    int value,ind;
    printf("Enter your bike slot number : ");
    scanf("%d",&value);
    ind=value-1;
    strcpy(data.customerName[ind],"0");
    data.vehicleNumber[ind]=0;
    strcpy(data.date[ind],"0");
}
void auto_checkout()
{
    int value,ind;
    printf("Enter your auto slot number : ");
    scanf("%d",&value);
    ind=value-1;
    strcpy(data.customerName[ind],"0");
    data.vehicleNumber[ind]=0;
    strcpy(data.date[ind],"0");
}
void check_vehicle()
{

    char customerName1[20], date1[13];
    int vehicleNumber,temp,j,k,low=0,mid,high=index1;
    int i = 0, check1, check2=1, check3;
    printf("\nPlease enter some details\n");
    printf("Enter Name: ");
    fflush(stdin);
    gets(customerName1);
    printf("Enter vehicle number: ");
    scanf("%d", &vehicleNumber);
    printf("Enter date: ");
    fflush(stdin);
    gets(date1);
    for(k= 0; k<=index1; k++)
    {
        for(j= 0; j<=index1-k -1; j++)
        {
            if(data.vehicleNumber[j]>data.vehicleNumber[j+1])
            {
                temp= data.vehicleNumber[j];
                data.vehicleNumber[j]=data.vehicleNumber[j+1];
                data.vehicleNumber[j+1]=temp;
            }
        }
    }
    while (low <= high)
    {
        mid =(low + high) / 2;
        if (data.vehicleNumber[mid] == vehicleNumber)
        {
            check2--;
            break;
        }
        else if (data.vehicleNumber[mid] < vehicleNumber)
            low = mid + 1;
        else
            high = mid - 1;
    }
    while (1)
    {
        check1 = strcmp(customerName1, data.customerName[i]);
        check3 = strcmp(date1, data.date[i]);
        if (check1 == 0 && check2 == 0 && check3 == 0)
        {
            printf("\nYour vehicle is available here\n");
            break;
        }
        else
        {
            printf("\nSorry! your vehicle is not available here\n");
            break;

        }
        i++;
    }
}
void check_insight()
{
    printf("\n*************Today's insight***************\n");
    printf("Total earnings: %d\n", earings);
    printf("Total Bus parked: %d\n", bus_count);
    printf("Total Car parked: %d\n", car_count);
    printf("Total Bike parked: %d\n", bike_count);
    printf("Total Auto parked: %d\n", auto_count);
}
int first( )
{
    printf("\n\t\t\t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb                                               \xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb        =============================          \xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb         VEHICLE PARKING MANAGEMENT            \xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb        =============================          \xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb                MD. JUEL RANA                  \xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb                   CSE-221                     \xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb                      D4                       \xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb        221002492@student.green.edu.bd         \xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb                                               \xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb                                               \xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n\n");
    printf(" \n\t Press Any Key To Continue:");

    getch();
    system("cls");
}
void second()
{
    printf("\n\t\t\t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb       ==============================         \xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb       Welcome To JUEL Parking Stand          \xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb       ==============================         \xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");

    printf("\n\t\t\t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb         This is vehicle fees chart            \xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb     Bus fees 200   \xdb   Car fees 150           \xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb===============================================\xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb     Bike fees 50   \xdb   Auto fees 100          \xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb                                               \xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb                  CHOICE                       \xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb                 ========                      \xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb                                               \xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb          Enter 1 for park your vehicle        \xdb\xdb\n");




    printf("\t\t\t\t\t\t\t\xdb\xdb          Enter 2 for check your vehicle       \xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb          Enter 3 for vehicle checkout         \xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb          Enter 4 for show today insight       \xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb          Enter 5 for exit                     \xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb                                               \xdb\xdb\n");
    printf("\t\t\t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n\n");

}

void main()
{
    first();

    int choose;
    do
    {
        second();
again:
        printf("\nPlease choose any option: ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            park_vehicle();
            break;
        case 2:
            check_vehicle();
            break;
        case 3:
            check_out();
            break;
        case 4:
            check_insight();
            break;
        case 5:
            printf("Thank you for using our parking stand\n");
            exit(0);
            break;
        default:
            printf("Invalid number try again\n");
            goto again;
            break;
        }
    }
    while (choose != 5);
    return 0;
}
