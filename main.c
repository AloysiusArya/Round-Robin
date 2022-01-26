#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i, l, total = 0, x, counter = 0, time_quantum;
      int waktu_tunggu = 0, waktu_tanggap = 0, waktu_kedatangan[10], waktu_eksekusi[10], temp[10];
      printf("\nMasukkan Jumlah Antrian:\t");
      scanf("%d", &l);
      x = l;
      for(i = 0; i < l; i++)
      {
            printf("\nMasukkan Detail Antrian[%d]\n", i + 1);
            printf("Waktu Kedatangan::\t");
            scanf("%d", &waktu_kedatangan[i]);
            printf("Waktu Eksekusi:\t");
            scanf("%d", &waktu_eksekusi[i]);
            temp[i] = waktu_eksekusi[i];
      }
      printf("\nMasukkan Quantum:\t");
      scanf("%d", &time_quantum);
      printf("\nProcess ID\t\tWaktu Eksekusi\t Waktu Tanggap\t Waktu Tunggu\n");
      for(total = 0, i = 0; x != 0;)
      {
            if(temp[i] <= time_quantum && temp[i] > 0)
            {
                  total = total + temp[i];
                  temp[i] = 0;
                  counter = 1;
            }
            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - time_quantum;
                  total = total + time_quantum;
            }
            if(temp[i] == 0 && counter == 1)
            {
                  x--;
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, waktu_eksekusi[i], total - waktu_kedatangan[i], total - waktu_kedatangan[i] - waktu_eksekusi[i]);
                  waktu_tunggu = waktu_tunggu + total - waktu_kedatangan[i] - waktu_eksekusi[i];
                  waktu_tanggap = waktu_tanggap + total - waktu_kedatangan[i];
                  counter = 0;
            }
            if(i == l - 1)
            {
                  i = 0;
            }
            else if(waktu_kedatangan[i + 1] <= total)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
      }
      return 0;
}

