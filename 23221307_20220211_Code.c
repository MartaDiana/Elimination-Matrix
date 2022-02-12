#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int pilihan;
// matriks ordo 2x2
#define dua_baris 2 
#define dua_kolom 3
// matriks ordo 3x3 
#define tiga_baris 3
#define tiga_kolom 4
const int m[dua_baris][dua_kolom];
const int n[tiga_baris][tiga_kolom];
int ret = 0;

int a, b, c , d, e, f, g, h, k, l, o, p, q, r, s, t, u, v, w, x, y, x1,x2,x3;

int main() {

    // memasukkan pilihan user
    printf("\nEliminasi Matriks Ordo \n");
    printf("\n1.Eliminasi Matriks Ordo 2x2\n");
    printf("\n2. Eliminasi Matriks Ordo 3x3\n");
    printf("\n Masukkan Pilihan: ");
    scanf("%d", &pilihan);

    // mengambil input matrix dari file .txt

    FILE *fp = fopen("D:/Institut Teknologi Bandung/Matematika Lanjut/Tugas 2/dua.txt", "r");

    if (!fp)
    {
        fprintf(stderr, "unable to open file");
        return 1;
    }

    switch (pilihan)
    {

    case 1: 
    printf("\n--------------Matriks Ordo 2x2---------------\n");
    // read matrix from file
    for (int i = 0; i < dua_baris && ret != EOF; i++)
    {
        for (int j = 0; j < dua_kolom && ret != EOF; j++)
        {
            ret = fscanf(fp, "%d", &m[i][j]);
            if (ret == 0)
            {
                fprintf(stderr, "error reading file");
                return 1;
            }
        }
    }
    
    fclose(fp);

    // print matrix
    for (int i = 0; i < dua_baris; i++)
    {
        for (int j = 0; j < dua_kolom; j++)
        {
            printf("%3d", m[i][j]); 
        }
        puts("");   
    }

    printf("\n");
    printf("Bentuk Aljabar dari Matriks diatas:\n");
    printf("----------------------------------------\n");

      // tampilin dalam bentuk aljabar
    // baris pertama
    if(m[0][0]==-1 && m[0][1]==-1)
    {
        printf("-x  -y = %i\n",m[0][2]);
    } 
    else if (m[0][0]==1 && m[0][1]==1)
    {
        printf("x  y = %i\n",m[0][2]);
    } 

    else if (m[0][0]==-1 && m[0][1]==1 )
    {
        printf("-x  y = %i \n",m[0][2]);        
    }

    
    else if (m[0][0]==1 && m[0][1]==-1 )
    {
        printf("x  -y = %i \n",m[0][2]);        
    }

    else if (m[0][0]==1)
    {
        printf("x  %iy = %i \n",m[0][1],m[0][2]);
    }

    else if (m[0][0]==-1)
    {
        printf("-x  %iy = %i \n",m[0][1],m[0][2]);
    }

    else if (m[0][1]==1)
    {
        printf("%ix  y = %i \n",m[0][0],m[0][2]);
    }

    else if (m[0][1]==-1)
    {
        printf("%ix  -y = %i \n",m[0][0],m[0][2]);
    }

    else 
    {
        printf("%ix  %iy = %i \n",m[0][0],m[0][1],m[0][2]);
    }  

    ////////// baris kedua

    if(m[1][0]==-1 && m[1][1]==-1)
    {
        printf("-x  -y = %i\n",m[1][2]);
    } 
    else if (m[1][0]==1 && m[1][1]==1)
    {
        printf("x  y = %i\n",m[1][2]);
    } 

    else if (m[1][0]==-1 && m[1][1]==1 )
    {
        printf("-x  y = %i \n",m[1][2]);        
    }

    
    else if (m[1][0]==1 && m[1][1]==-1 )
    {
        printf("x  -y = %i \n",m[1][2]);        
    }

    else if (m[1][0]==1)
    {
        printf("x  %iy = %i \n",m[1][1],m[1][2]);
    }

    else if (m[1][0]==-1)
    {
        printf("-x  %iy = %i \n",m[1][1],m[1][2]);
    }

    else if (m[1][1]==1)
    {
        printf("%ix  y = %i \n",m[1][0],m[1][2]);
    }

    else if (m[1][1]==-1)
    {
        printf("%ix  -y = %i \n",m[1][0],m[1][2]);
    }

    else 
    {
        printf("%ix  %iy = %i \n",m[1][0],m[1][1],m[1][2]);
    }  

    printf("\n");

    // elimnasi
    printf("Hasil Eliminasi (menghilangkan variabel X): \n");
    a=((m[0][0]*m[1][0]) - (m[1][0]*m[0][0]));
    b=((m[0][1]*m[1][0]) - (m[1][1]*m[0][0])); 
        if (b == -1)
        {
            printf("-y ");
        }
        else if (b==1)
        {
            printf("y ");
        }
        else
        {
            printf("%iy ",b);
        }
    c=((m[0][2]*m[1][0]) - (m[1][2]*m[0][0]))  ;  printf("= %i ",c);

    printf("\n");
    d=(c/b); //hasil akar dari variabel Y
    f= (m[0][2]-m[0][1]*d)/m[0][0]; //formula x
    printf("y = %d\n", d);

    printf("\n");
    printf("Mencari Nilai x, dari persamaan baris-1 =\n");
    // tampilkan subtisusi matriks X
    printf("x = (%i",m[0][2]);
    printf("-%i", m[0][1]);
    printf("*%i)",d);
    printf("/%i", m[0][0]);

    printf("\n");
    printf("x = %d\n", f);
    
    // kesimpulan hasil akar akarnya
    printf("Maka akar-akarnya:\n");
    printf("X1: %d\n", f);
    printf("X2: %d", d); 
        break;


    case 2: 

    printf("\n--------------Matriks Ordo 3x3---------------\n");

        // read matrix from file
    for (int i = 0; i < tiga_baris && ret != EOF; i++)
    {
        for (int j = 0; j < tiga_kolom && ret != EOF; j++)
        {
            ret = fscanf(fp, "%d", &n[i][j]);
            if (ret == 0)
            {
                fprintf(stderr, "error reading file");
                return 1;
            }
        }
    }
    
    fclose(fp);

        for (int i = 0; i < tiga_baris; i++)
    {
        for (int j = 0; j < tiga_kolom; j++)
        {
            printf("%3d", n[i][j]); 
        }
        puts("");   
    }

    printf("\n");
    printf("Bentuk Aljabar dari Matriks diatas:\n");
    printf("----------------------------------------\n");
    // baris pertama
    if (n[0][0]==-1 && n[0][1]==-1 && n[0][2]==-1)
    {
        printf("-x  -y  -z = %i \n",n[0][3]);
    }
    else if (n[0][0]==1 && n[0][1]==1 && n[0][2]==1)
    {
        printf("x  y  z = %i \n",n[0][3]);
    }
    else if(n[0][0]==1 && n[0][1]==1 && n[0][2]==-1)
    {
        printf("x  y  -z = %i \n",n[0][3]);
    }
    else if(n[0][0]==1 && n[0][1]==-1 && n[0][2]==1)
    {
        printf("x  -y  z = %i \n",n[0][3]);
    }
    else if(n[0][0]==-1 && n[0][1]==1 && n[0][2]==1)
    {
        printf("-x  y  z = %i \n",n[0][3]);
    }
    else if(n[0][0]==-1 && n[0][1]==-1 && n[0][2]==1)
    {
        printf("-x  -y  z = %i \n",n[0][3]);
    }
    else if(n[0][0]==-1 && n[0][1]==1 && n[0][2]==-1)
    {
        printf("-x  y  -z = %i \n",n[0][3]);
    }
    else if(n[0][0]==1 && n[0][1]==-1 && n[0][2]==-1)
    {
        printf("x  -y  -z = %i \n",n[0][3]);
    }
    else if(n[0][0]==1 && n[0][1]==1)
    {
        printf("x  y  %iz = %i \n",n[0][2],n[0][3]);
    }
    else if(n[0][0]==1 && n[0][1]==-1)
    {
        printf("x  -y  %iz = %i \n",n[0][2],n[0][3]);
    }
    else if(n[0][0]==-1 && n[0][1]==1)
    {
        printf("-x  y  %iz = %i \n",n[0][2],n[0][3]);
    }
    else if(n[0][0]==-1 && n[0][1]==-1)
    {
        printf("-x  -y  %iz = %i \n",n[0][2],n[0][3]);
    }
    else if(n[0][0]==1 && n[0][2]==1)
    {
        printf("x  %iy  z = %i \n",n[0][1],n[0][3]);
    }
    else if(n[0][0]==1 && n[0][2]==-1)
    {
        printf("x  %iy  -z = %i \n",n[0][1],n[0][3]);
    }
    else if(n[0][0]==-1 && n[0][2]==1)
    {
        printf("-x  %iy  z = %i \n",n[0][1],n[0][3]);
    }
    else if(n[0][0]==-1 && n[0][2]==-1)
    {
        printf("-x  %iy  -z = %i \n",n[0][1],n[0][3]);
    }
    else if(n[0][1]==1 && n[0][2]==1)
    {
        printf("%ix  y  z = %i \n",n[0][0],n[0][3]);
    }
    else if(n[0][1]==1 && n[0][2]==-1)
    {
        printf("%ix  y  -z = %i \n",n[0][0],n[0][3]);
    }
    else if(n[0][1]==-1 && n[0][2]==1)
    {
        printf("%ix  -y  z = %i \n",n[0][0],n[0][3]);
    }
    else if(n[0][1]==-1 && n[0][2]==-1)
    {
        printf("%ix  -y  -z = %i \n",n[0][0],n[0][3]);
    }
    else if(n[0][0]==1)
    {
        printf("x  %iy  %iz = %i \n",n[0][1],n[0][2],n[0][3]);
    }
    else if(n[0][0]==-1)
    {
        printf("-x  %iy  %iz = %i \n",n[0][1],n[0][2],n[0][3]);
    }
    else if(n[0][1]==1)
    {
        printf("%ix  y  %iz = %i \n",n[0][0],n[0][2],n[0][3]);
    }
    else if(n[0][1]==-1)
    {
        printf("%ix  -y  %iz = %i \n",n[0][0],n[0][2],n[0][3]);
    }
    else if(n[0][2]==1)
    {
        printf("%ix  %iy  z = %i \n",n[0][0],n[0][1],n[0][3]);
    }
    else if(n[0][2]==-1)
    {
        printf("%ix  %iy  -z = %i \n",n[0][0],n[0][1],n[0][3]);
    }
    else
    {
        printf("%ix  %iy  %iz = %i \n",n[0][0],n[0][1],n[0][2], n[0][3]); 
    }

    // baris ke-dua 

    if (n[1][0]==-1 && n[1][1]==-1 && n[1][2]==-1)
    {
        printf("-x  -y  -z = %i \n",n[1][3]);
    }
    else if (n[1][0]==1 && n[1][1]==1 && n[1][2]==1)
    {
        printf("x  y  z = %i \n",n[1][3]);
    }
    else if(n[1][0]==1 && n[1][1]==1 && n[1][2]==-1)
    {
        printf("x  y  -z = %i \n",n[1][3]);
    }
    else if(n[1][0]==1 && n[1][1]==-1 && n[1][2]==1)
    {
        printf("x  -y  z = %i \n",n[1][3]);
    }
    else if(n[1][0]==-1 && n[1][1]==1 && n[1][2]==1)
    {
        printf("-x  y  z = %i \n",n[1][3]);
    }
    else if(n[1][0]==-1 && n[1][1]==-1 && n[1][2]==1)
    {
        printf("-x  -y  z = %i \n",n[1][3]);
    }
    else if(n[1][0]==-1 && n[1][1]==1 && n[1][2]==-1)
    {
        printf("-x  y  -z = %i \n",n[1][3]);
    }
    else if(n[1][0]==1 && n[1][1]==-1 && n[1][2]==-1)
    {
        printf("x  -y  -z = %i \n",n[1][3]);
    }
    else if(n[1][0]==1 && n[1][1]==1)
    {
        printf("x  y  %iz = %i \n",n[1][2],n[1][3]);
    }
    else if(n[1][0]==1 && n[1][1]==-1)
    {
        printf("x  -y  %iz = %i \n",n[1][2],n[1][3]);
    }
    else if(n[1][0]==-1 && n[1][1]==1)
    {
        printf("-x  y  %iz = %i \n",n[1][2],n[1][3]);
    }
    else if(n[1][0]==-1 && n[1][1]==-1)
    {
        printf("-x  -y  %iz = %i \n",n[1][2],n[1][3]);
    }
    else if(n[1][0]==1 && n[1][2]==1)
    {
        printf("x  %iy  z = %i \n",n[1][1],n[1][3]);
    }
    else if(n[1][0]==1 && n[1][2]==-1)
    {
        printf("x  %iy  -z = %i \n",n[1][1],n[1][3]);
    }
    else if(n[1][0]==-1 && n[1][2]==1)
    {
        printf("-x  %iy  z = %i \n",n[1][1],n[1][3]);
    }
    else if(n[1][0]==-1 && n[1][2]==-1)
    {
        printf("-x  %iy  -z = %i \n",n[1][1],n[1][3]);
    }
    else if(n[1][1]==1 && n[1][2]==1)
    {
        printf("%ix  y  z = %i \n",n[1][0],n[1][3]);
    }
    else if(n[1][1]==1 && n[1][2]==-1)
    {
        printf("%ix  y  -z = %i \n",n[1][0],n[1][3]);
    }
    else if(n[1][1]==-1 && n[1][2]==1)
    {
        printf("%ix  -y  z = %i \n",n[1][0],n[1][3]);
    }
    else if(n[1][1]==-1 && n[1][2]==-1)
    {
        printf("%ix  -y  -z = %i \n",n[1][0],n[1][3]);
    }
    else if(n[1][0]==1)
    {
        printf("x  %iy  %iz = %i \n",n[1][1],n[1][2],n[1][3]);
    }
    else if(n[1][0]==-1)
    {
        printf("-x  %iy  %iz = %i \n",n[1][1],n[1][2],n[1][3]);
    }
    else if(n[1][1]==1)
    {
        printf("%ix  y  %iz = %i \n",n[1][0],n[1][2],n[1][3]);
    }
    else if(n[1][1]==-1)
    {
        printf("%ix  -y  %iz = %i \n",n[1][0],n[1][2],n[1][3]);
    }
    else if(n[1][2]==1)
    {
        printf("%ix  %iy  z = %i \n",n[1][0],n[1][1],n[1][3]);
    }
    else if(n[1][2]==-1)
    {
        printf("%ix  %iy  -z = %i \n",n[1][0],n[1][1],n[1][3]);
    }
    else
    {
        printf("%ix  %iy  %iz = %i \n",n[1][0],n[1][1],n[1][2], n[1][3]); 
    }

    // baris ketiga
    if (n[2][0]==-1 && n[2][1]==-1 && n[2][2]==-1)
    {
        printf("-x  -y  -z = %i \n",n[2][3]);
    }
    else if (n[2][0]==1 && n[2][1]==1 && n[2][2]==1)
    {
        printf("x  y  z = %i \n",n[2][3]);
    }
    else if(n[2][0]==1 && n[2][1]==1 && n[2][2]==-1)
    {
        printf("x  y  -z = %i \n",n[2][3]);
    }
    else if(n[2][0]==1 && n[2][1]==-1 && n[2][2]==1)
    {
        printf("x  -y  z = %i \n",n[2][3]);
    }
    else if(n[2][0]==-1 && n[2][1]==1 && n[2][2]==1)
    {
        printf("-x  y  z = %i \n",n[2][3]);
    }
    else if(n[2][0]==-1 && n[2][1]==-1 && n[2][2]==1)
    {
        printf("-x  -y  z = %i \n",n[2][3]);
    }
    else if(n[2][0]==-1 && n[2][1]==1 && n[2][2]==-1)
    {
        printf("-x  y  -z = %i \n",n[2][3]);
    }
    else if(n[2][0]==1 && n[2][1]==-1 && n[2][2]==-1)
    {
        printf("x  -y  -z = %i \n",n[2][3]);
    }
    else if(n[2][0]==1 && n[2][1]==1)
    {
        printf("x  y  %iz = %i \n",n[2][2],n[2][3]);
    }
    else if(n[2][0]==1 && n[2][1]==-1)
    {
        printf("x  -y  %iz = %i \n",n[2][2],n[2][3]);
    }
    else if(n[2][0]==-1 && n[2][1]==1)
    {
        printf("-x  y  %iz = %i \n",n[2][2],n[2][3]);
    }
    else if(n[2][0]==-1 && n[2][1]==-1)
    {
        printf("-x  -y  %iz = %i \n",n[2][2],n[2][3]);
    }
    else if(n[2][0]==1 && n[2][2]==1)
    {
        printf("x  %iy  z = %i \n",n[2][1],n[2][3]);
    }
    else if(n[2][0]==1 && n[2][2]==-1)
    {
        printf("x  %iy  -z = %i \n",n[2][1],n[2][3]);
    }
    else if(n[2][0]==-1 && n[2][2]==1)
    {
        printf("-x  %iy  z = %i \n",n[2][1],n[2][3]);
    }
    else if(n[2][0]==-1 && n[2][2]==-1)
    {
        printf("-x  %iy  -z = %i \n",n[2][1],n[2][3]);
    }
    else if(n[2][1]==1 && n[2][2]==1)
    {
        printf("%ix  y  z = %i \n",n[2][0],n[2][3]);
    }
    else if(n[2][1]==1 && n[2][2]==-1)
    {
        printf("%ix  y  -z = %i \n",n[2][0],n[2][3]);
    }
    else if(n[2][1]==-1 && n[2][2]==1)
    {
        printf("%ix  -y  z = %i \n",n[2][0],n[2][3]);
    }
    else if(n[2][1]==-1 && n[2][2]==-1)
    {
        printf("%ix  -y  -z = %i \n",n[2][0],n[2][3]);
    }
    else if(n[2][0]==1)
    {
        printf("x  %iy  %iz = %i \n",n[2][1],n[2][2],n[2][3]);
    }
    else if(n[2][0]==-1)
    {
        printf("-x  %iy  %iz = %i \n",n[2][1],n[2][2],n[2][3]);
    }
    else if(n[2][1]==1)
    {
        printf("%ix  y  %iz = %i \n",n[2][0],n[2][2],n[2][3]);
    }
    else if(n[2][1]==-1)
    {
        printf("%ix  -y  %iz = %i \n",n[2][0],n[2][2],n[2][3]);
    }
    else if(n[2][2]==1)
    {
        printf("%ix  %iy  z = %i \n",n[2][0],n[2][1],n[2][3]);
    }
    else if(n[2][2]==-1)
    {
        printf("%ix  %iy  -z = %i \n",n[2][0],n[2][1],n[2][3]);
    }
    else
    {
        printf("%ix  %iy  %iz = %i \n",n[2][0],n[2][1], n[2][2], n[2][3]);
    }
    // printf("%ix  %iy  %iz = %i \n",n[0][0],n[0][1],n[0][2], n[0][3]);
    // printf("%ix  %iy  %iz = %i \n",n[1][0],n[1][1], n[1][2], n[1][3]);
    // printf("%ix  %iy  %iz = %i \n",n[2][0],n[2][1], n[2][2], n[2][3]);
    printf("\n");

    // eliminasi persamaan 1 dan 2
    printf("Eliminasi Persamaan 1 dengan Persamaan 2\n");
    printf("Hasil Eliminasi 1:\n");
    g= ((n[0][0]*n[1][0]) - (n[1][0]*n[0][0]));
    h= ((n[0][1]*n[1][0]) - (n[1][1]*n[0][0]));
        if (h == -1)
        {
            printf("-y ");
        }
        else if (h==1)
        {
            printf("y ");
        }
        else
        {
            printf("%iy ",h);
        }
    k= ((n[0][2]*n[1][0]) - (n[1][2]*n[0][0]));
        if (k == -1)
        {
            printf("-z ");
        }
        else if (k==1)
        {
            printf("z ");
        }
        else
        {
            printf("%iz",k);
        }
    l= ((n[0][3]*n[1][0]) - (n[1][3]*n[0][0])); printf(" = %i",l);

    printf("\n");

    // eliminasi persamaan 2 dan 3
    printf("Eliminasi Persamaan 2 dengan Persamaan 3\n");
    printf("Hasil Eliminasi 2:\n");
    o= ((n[1][0]*n[2][0]) - (n[2][0]*n[1][0]));
    p= ((n[1][1]*n[2][0]) - (n[2][1]*n[1][0])); 
        if (p == -1)
        {
            printf("-y ");
        }
        else if (p==1)
        {
            printf("y ");
        }
        else
        {
            printf("%iy ",p);
        }
    q= ((n[1][2]*n[2][0]) - (n[2][2]*n[1][0]));
        if (q == -1)
        {
            printf("-z ");
        }
        else if (q==1)
        {
            printf("z ");
        }
        else
        {
            printf("%iz",q);
        }
    r= ((n[1][3]*n[2][0]) - (n[2][3]*n[1][0])); printf(" = %i",r);

    printf("\nEliminasi Hasil Eliminasi 1 dan 2\n");

    h= ((n[0][1]*n[1][0]) - (n[1][1]*n[0][0])); 
            if (h == -1)
            {
                printf("-y ");
            }
            else if (h==1)
            {
                printf("y ");
            }
            else
            {
                printf("%iy ",h);
            }
    k= ((n[0][2]*n[1][0]) - (n[1][2]*n[0][0]));
            if (k == -1)
            {
                printf("-z ");
            }
            else if (k==1)
            {
                printf("z ");
            }
            else
            {
                printf("%iz ",k);
            }
    l= ((n[0][3]*n[1][0]) - (n[1][3]*n[0][0])); printf(" = %i",l);
    printf("\n");
    p= ((n[1][1]*n[2][0]) - (n[2][1]*n[1][0]));
            if (p == -1)
            {
                printf("-y ");
            }
            else if (p==1)
            {
                printf("y ");
            }
            else
            {
                printf("%iy ",p);
            }
    q= ((n[1][2]*n[2][0]) - (n[2][2]*n[1][0]));
            if (q == -1)
            {
                printf("-z ");
            }
            else if (q==1)
            {
                printf("z ");
            }
            else
            {
                printf("%iz ",q);
            }
    r= ((n[1][3]*n[2][0]) - (n[2][3]*n[1][0])); printf(" = %i",r);
    printf("\n");
    printf("----------- -");
    printf("\n");

    s = (h*p) - (p*h);
    t = (k*p) - (q*h);
            if (t == -1)
            {
                printf("-z ");
            }
            else if (t==1)
            {
                printf("z ");
            }
            else
            {
                printf("%iz ",t);
            }
    u = (l*p) - (r*h); printf("%i\n",u);
    v = u/t; //nilai z
    printf("z = %d", v);
    printf("\n");
    printf("Mencari nilai y:\n");
    
    h= ((n[0][1]*n[1][0]) - (n[1][1]*n[0][0]));
            if (h == -1)
            {
                printf("-y ");
            }
            else if (h==1)
            {
                printf("y ");
            }
            else
            {
                printf("%iy ",h);
            }
    w= k*v; printf("%i = ",w);
    l= ((n[0][3]*n[1][0]) - (n[1][3]*n[0][0])); printf("%i",l);
    
    // cari nilai y
    
    x = (l-w)/h; //nilai y
    printf("\n");
    printf("y = %d", x);

    // cari nilai x

    printf("\n");
    printf("Mencari nilai x dengan substitusi persamaan 1:\n");
    // printf("%ix  %iy  %iz = %i \n",n[0][0],n[0][1],n[0][2], n[0][3]);
    // baris pertama
    if (n[0][0]==-1 && n[0][1]==-1 && n[0][2]==-1)
    {
        printf("-x  -y  -z = %i \n",n[0][3]);
    }
    else if (n[0][0]==1 && n[0][1]==1 && n[0][2]==1)
    {
        printf("x  y  z = %i \n",n[0][3]);
    }
    else if(n[0][0]==1 && n[0][1]==1 && n[0][2]==-1)
    {
        printf("x  y  -z = %i \n",n[0][3]);
    }
    else if(n[0][0]==1 && n[0][1]==-1 && n[0][2]==1)
    {
        printf("x  -y  z = %i \n",n[0][3]);
    }
    else if(n[0][0]==-1 && n[0][1]==1 && n[0][2]==1)
    {
        printf("-x  y  z = %i \n",n[0][3]);
    }
    else if(n[0][0]==-1 && n[0][1]==-1 && n[0][2]==1)
    {
        printf("-x  -y  z = %i \n",n[0][3]);
    }
    else if(n[0][0]==-1 && n[0][1]==1 && n[0][2]==-1)
    {
        printf("-x  y  -z = %i \n",n[0][3]);
    }
    else if(n[0][0]==1 && n[0][1]==-1 && n[0][2]==-1)
    {
        printf("x  -y  -z = %i \n",n[0][3]);
    }
    else if(n[0][0]==1 && n[0][1]==1)
    {
        printf("x  y  %iz = %i \n",n[0][2],n[0][3]);
    }
    else if(n[0][0]==1 && n[0][1]==-1)
    {
        printf("x  -y  %iz = %i \n",n[0][2],n[0][3]);
    }
    else if(n[0][0]==-1 && n[0][1]==1)
    {
        printf("-x  y  %iz = %i \n",n[0][2],n[0][3]);
    }
    else if(n[0][0]==-1 && n[0][1]==-1)
    {
        printf("-x  -y  %iz = %i \n",n[0][2],n[0][3]);
    }
    else if(n[0][0]==1 && n[0][2]==1)
    {
        printf("x  %iy  z = %i \n",n[0][1],n[0][3]);
    }
    else if(n[0][0]==1 && n[0][2]==-1)
    {
        printf("x  %iy  -z = %i \n",n[0][1],n[0][3]);
    }
    else if(n[0][0]==-1 && n[0][2]==1)
    {
        printf("-x  %iy  z = %i \n",n[0][1],n[0][3]);
    }
    else if(n[0][0]==-1 && n[0][2]==-1)
    {
        printf("-x  %iy  -z = %i \n",n[0][1],n[0][3]);
    }
    else if(n[0][1]==1 && n[0][2]==1)
    {
        printf("%ix  y  z = %i \n",n[0][0],n[0][3]);
    }
    else if(n[0][1]==1 && n[0][2]==-1)
    {
        printf("%ix  y  -z = %i \n",n[0][0],n[0][3]);
    }
    else if(n[0][1]==-1 && n[0][2]==1)
    {
        printf("%ix  -y  z = %i \n",n[0][0],n[0][3]);
    }
    else if(n[0][1]==-1 && n[0][2]==-1)
    {
        printf("%ix  -y  -z = %i \n",n[0][0],n[0][3]);
    }
    else if(n[0][0]==1)
    {
        printf("x  %iy  %iz = %i \n",n[0][1],n[0][2],n[0][3]);
    }
    else if(n[0][0]==-1)
    {
        printf("-x  %iy  %iz = %i \n",n[0][1],n[0][2],n[0][3]);
    }
    else if(n[0][1]==1)
    {
        printf("%ix  y  %iz = %i \n",n[0][0],n[0][2],n[0][3]);
    }
    else if(n[0][1]==-1)
    {
        printf("%ix  -y  %iz = %i \n",n[0][0],n[0][2],n[0][3]);
    }
    else if(n[0][2]==1)
    {
        printf("%ix  %iy  z = %i \n",n[0][0],n[0][1],n[0][3]);
    }
    else if(n[0][2]==-1)
    {
        printf("%ix  %iy  -z = %i \n",n[0][0],n[0][1],n[0][3]);
    }
    else
    {
        printf("%ix  %iy  %iz = %i \n",n[0][0],n[0][1],n[0][2], n[0][3]); 
    }


    y= ((n[0][3] - n[0][2]*v - n[0][1]*x))/(n[0][0]); //nilai x
    printf("x = %d\n", y);

    //hasil akar2

    printf("Maka hasil akar-akarnya: \n");
    printf("X1 = %d\n", y);
    printf("X2 = %d\n", x);
    printf("X3 = %d\n", v);
    
    default:
        break;
    }

    return 0;

}

