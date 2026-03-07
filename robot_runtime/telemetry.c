/*# 1. Telemetry System (Ring Buffer)

The telemetry system stores the **last 10 sensor readings**.

If more than 10 readings are added, the **oldest value is overwritten**.

Example:

```
SAMPLE 1
SAMPLE 2
...
SAMPLE 10
SAMPLE 11
```

Buffer contents:

```
2 3 4 5 6 7 8 9 10 11
```

## Commands

### SAMPLE <value>

Adds a new sensor reading.

Example:

```
SAMPLE 12
```

---

### STATS

Print statistics of stored readings.

Example output:

```
COUNT=3 MIN=4 MAX=10 AVG=7.00
```

If no readings exist:

```
EMPTY
```

---

### DUMP

Print all stored samples.

Example:

```
SAMPLES: 10 4 7
```

If empty:

```
SAMPLES:
```

---
*/

/*create a sliding window buffer function to delete last element of array and add new last element*/
#include <stdio.h>
#include <string.h>

void sliding_window(int size, int arr[], int next)
{
    for (int i = 0; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = next;
}

int min(int size, int arr[])
{
    int min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (min > arr[i])
            min = arr[i];
    }
    return min;
}

int max(int size, int arr[])
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

float avg(int size, int arr[])
{
    float avg;
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum = sum + arr[i];

    avg = (float)sum / size;

    return avg;
}

int main(void)
{
    int value;
    char cmd[20];

    int data[10];

    int i = 1;
    int n = 0;
    while (i != 0)
    {

        scanf("%19s %d", cmd, &value);

        if (strcmp(cmd, "sample") == 0)
        {
            if (n < 10)
            {
                data[n] = value;
                n++;
            }
            else
            {
                sliding_window(n, data, value);
            }
        }
        else if (strcmp(cmd, "stats") == 0)
        {
            if (n == 0)
            {
                printf("EMPTY\n");
            }

            else
            {
                int min_elmt;
                int max_elmt;
                float avg_elmt;
                min_elmt = min(n, data);
                max_elmt = max(n, data);
                avg_elmt = avg(n, data);

                printf("%d %d %.2f\n", min_elmt, max_elmt, avg_elmt);
            }
        }
        else if (strcmp(cmd, "dump") == 0)
        {
        }
        else if (strcmp(cmd, "quit") == 0)
        {
            i = 0;
        }
        else
        {
            printf("ERROR: command does not exist\n");
            i = 0;
        }
    }
}
