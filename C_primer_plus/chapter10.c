#include <stdio.h>
#include <stdlib.h>

void start_use_array()
{
    int powers[8] = {1, 2, 4, 6, 8, 16, 32, 64};

    int no_data[4];
    int i;

    for (i = 0; i < 4; i++)
    {
        printf("%2d%14d\n", i, no_data[i]);
    }
}

#define ARR_LEN 5
#define MONTHS 12


void use_array_and_point()
{
    int arr[ARR_LEN] = {1, 2, 3, 4, 5};
    printf("array name:      arr point is %p \n", arr);
    printf("array first  element point is %p \n", &arr[0]);
    printf("array second element point is %p \n", &arr[1]);
}


void point_add_usage()
{
    short dates[ARR_LEN];
    short *ptr;

    double bills[ARR_LEN];
    double *ptf;

    // ptr = dates;
    ptr = &dates[0];
    ptf = bills;

    printf("%23s %15s\n", "short", "double");
    for (short index = 0; index < ARR_LEN; index++)
    {
        printf("pointers + %d: %10p %10p\n", index, ptr + index, ptf + index);
    }

    // dates + 2 == &dates[2] ;     // same address
    // *(dates + 2) == dates[2] ;   // same value

    int days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int index;

    for (index = 0; index < MONTHS; index++)
        printf("Month %2d has %d days.\n", index + 1, *(days + index));
}

int sum_array(int *arr, int len)
{
    printf("arr addr %p \n", arr);

    int total = 0;
    for (int i = 0; i < len; i++)
    {
        total += *(arr + i);
    }

    return total;
}

int sum(const int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += *(arr + i);
    }
    return sum;
}

void run_with_sum_array()
{
    int arr1[ARR_LEN] = {1, 2, 3, 4, 5};
    printf("arr addr: %p \n", arr1);
    printf("arr[0] addr: %p \n", &arr1[0]);

    int sum = sum_array(arr1, ARR_LEN);
    printf("sum is %d\n", sum);

    int *p_arr = malloc(ARR_LEN * sizeof(int));
    if (NULL == p_arr)
    {
        exit(1);
    }

    *p_arr = 34;
    *(p_arr + 1) = 35;
    *(p_arr + 2) = 45;
    *(p_arr + 3) = 21;
    *(p_arr + 4) = 33;
    printf("sum is %d\n", sum_array(p_arr, ARR_LEN));

    free(p_arr);
}


void option_of_opint()
{
    int urn[5] = {100, 200, 300, 400, 500};
    int *ptr1, *ptr2, *ptr3;

    ptr1 = urn;
    ptr2 = &urn[2];

    printf("pointer value, dereferenced pointer, pointer address:\n");
    printf("ptr1 = %p, *ptr1 =%d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);

    ptr3 = ptr1 + 4;
    printf("\nadding an int to a pointer:\n");
    printf("ptr1 + 4 = %p, *(ptr1 + 4) = %d\n", ptr1 + 4, *(ptr1 + 4));

    ptr1++;
    printf("\nvalues after ptr1++:\n");
    printf("ptr1 = %p, *ptr1 =%d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);

    ptr2--;
    printf("\nvalues after --ptr2:\n");
    printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n", ptr2, *ptr2, &ptr2);

    --ptr1;
    ++ptr2;
    printf("\nPointers reset to original values:\n");
    printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);

    printf("\nsubtracting one pointer from another:\n");
    printf("ptr2 = %p, ptr1 = %p, ptr2 - ptr1 = %td\n", ptr2, ptr1, ptr2 - ptr1);

    printf("\nsubtracting an int from a pointer:\n");
    printf("ptr3 = %p, ptr3 - 2 = %p\n", ptr3, ptr3 - 2);
}


void const_usage()
{
    const int days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // days[9] = 44;  // not allow

    double rates[5] = {11.22, 33.33, 44.44, 55.55};
    const double locked[4] = {0.08, 0.075, 0.0725, 0.07};

    const double *pt = rates;

    // *(pt + 0) = 23.33;  // not allow
    // pt[2] = 232;       // not allow
    rates[0] = 99.99;
    // pt++;  // let point to next address

    const double *pc = rates;
    pc = locked;
    pc = &rates[3];

    double *pnc = locked;
    // pnc = &rates[3];
    *pnc = 34.44;
    // *locked = 34.44;

    for (int i = 0; i < 4; ++i)
    {
        printf("%f \n", *(locked + i));
    }
}


/*
 * =================================================================================
 * Multi Array
 *
 *
 */

void multi_array()
{
    int zippo[4][2] = {
        {4, 5},
        {1, 5},
        {6, 7},
        {3, 8}
    };

    int *ptr1 = zippo;

    for (int i = 0; i < 8; ++i)
    {
        printf("%p: %d\n", ptr1 + i, *(ptr1 + i));
    }

    /*
    zippo        2 int address
    zippo[0]     1 int address

     */

    printf("zippo   addr: %p \n", zippo);
    printf("zippo+1 addr: %p \n", zippo + 1);

    printf("*zippo  = %p \n", *zippo);
    printf("*zippo[0]  = %d \n", *(zippo[0] + 1));

    printf("   zippo = %p,    zippo + 1 = %p\n", zippo, zippo + 1);
    printf("zippo[0] = %p, zippo[0] + 1 = %p\n", zippo[0], zippo[0] + 1);
    printf("  *zippo = %p,   *zippo + 1 = %p\n", *zippo, *zippo + 1);
    printf("zippo[0][0] = %d\n", zippo[0][0]);
    printf("  *zippo[0] = %d\n", *zippo[0]);
    printf("    **zippo = %d\n", **zippo);
    printf("      zippo[2][1] = %d\n", zippo[2][1]);
    printf("*(*(zippo+2) + 1) = %d\n", *(*(zippo + 2) + 1));

    int (*pz)[2] = zippo;
    printf("pz   addr: %p \n", pz);
    printf("pz+1 addr: %p \n", pz + 1);
    printf("*pz + 1      addr: %p \n", *pz + 1);
    printf("*(*pz + 1)  value: %d \n", *(*pz + 1));

    printf("   pz = %p,    pz + 1 = %p\n", pz, pz + 1); // addr , addr + 2*int
    printf("pz[0] = %p, pz[0] + 1 = %p\n", pz[0], pz[3] + 1); // 0,0  *(pz + 3) + 1  3,1 addr
    printf("  *pz = %p,   *pz + 1 = %p\n", *pz, *pz + 1); // 0,0 addr / 0,1 addr
    printf("pz[0][0] = %d\n", pz[0][0]); // 0,0  value
    printf("  *pz[0] = %d\n", *pz[0]); // 0,0 value
    printf("    **pz = %d\n", **pz); // 0, 0 value
    printf("      pz[2][1] = %d\n", pz[2][1]); //
    printf("*(*(pz+2) + 1) = %d\n", *(*(pz + 2) + 1)); // 2, 1 value
}
