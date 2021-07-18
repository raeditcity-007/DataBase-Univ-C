#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
//Deklarasi Fungsi
void menu();
void tambah_univ();
void tampil_univ();
void edit_univ();
void hapus_univ();
void cari_univ();
void close();
void header();
//Deklarasi Struck
struct universitas{
	char namauniversitas[50];
	int kode;
	int rangking;
	int tahun;
	char akreditasi[2];
	char alamat[30];
}tambah,cek,hapus,temp;
//Menampilkan Tanggal
struct date{
	int tgl;
	int bln;
	int thn;
};
int main(){
	system("cls");
		printf("Now Loading");
		Sleep(500);
		printf(". ");
		Sleep(500);
		printf(". ");
		Sleep(500);
		printf(". ");
		Sleep(500);
		printf(". ");
		Sleep(500);
		printf(". ");
	menu();
	return 0;
}
void header(){
	printf("\nTTS ASISTEN DOSEN ASD!");
	time_t mytime;
	time(&mytime);
	printf("\n%s", ctime(&mytime));
}
//Menu
void menu(){
	int pilih;
	system("cls");
	printf("\n\nTTS ASDOS\nProgram Database Universitas\n\nNama Anggota :\n1. Panca Rizki Perkasa\nNIM : 672019023\n2. Radithya Airlangga\nNIM : 672019007");
    getch();
    system("cls");
	menu:
		system("cls");
		header();
		printf("MENU DATABASE UNIVERSITAS :");
		printf("\n[1]. Tambah Data Universitas");
		printf("\n[2]. Tampil Data Universitas");
		printf("\n[3]. Cari Data Lengkap Universitas");
		printf("\n[4]. Hapus Data Universitas");
		printf("\n[5]. Edit Data Universitas");
		printf("\n[6]. Keluar");
		printf("\n\nInput Pilihan Nomor Menu : ");
		scanf("%d", &pilih);
		switch(pilih){
			case 1:tambah_univ();
				break;
			case 2:tampil_univ();
				break;
			case 3: cari_univ();
				break;
			case 4:hapus_univ();
				break;
            case 5:edit_univ();
				break;
			case 6:close();
				break;
			default:printf("\nMohon Maaf Pilihan Anda Salah !");
				getche();
				goto menu;
		}
}
//Menambah Data
void tambah_univ(){
	FILE *ptr,*ptr1;
	int count=0;
	ptr =fopen("univ.txt","a");
		system("cls");
		ptr1 =fopen("univ.txt","r");
		while (fscanf (ptr1,"%d;%[^;];%[^;];%d;%d;%[^;]\n",&tambah.kode,tambah.namauniversitas,tambah.alamat,&tambah.rangking,&tambah.tahun,tambah.akreditasi)!=EOF)
        {tambah.kode++;
		}cek.kode = tambah.kode;
		fclose(ptr1);
		printf ("Masukan Nama Universitas : ");fflush(stdin);
		scanf ("%[^\n]",tambah.namauniversitas);
		printf ("Masukan Alamat Universitas : ");fflush(stdin);
		scanf ("%[^\n]",tambah.alamat);
		printf ("Masukan Rangking Universitas : ");fflush(stdin);
		scanf ("%d",&tambah.rangking);
		printf ("Masukan Tahun Berdiri Universitas : ");fflush(stdin);
		scanf ("%d",&tambah.tahun);
		printf ("Masukan Akreditasi Universitas : ");fflush(stdin);
		scanf ("%[^\n]",tambah.akreditasi);
		fprintf(ptr,"%d;%s;%s;%d;%d;%s;\n",tambah.kode,tambah.namauniversitas,tambah.alamat,tambah.rangking,tambah.tahun,tambah.akreditasi);
		fclose(ptr);

		printf("\n\nData Universitas Sudah Disimpan !");
		add_invalid:
		printf("\n\n\tEnter 1 untuk menu utama dan 0 untuk keluar : ");
		switch(getch()){
    		case '1': menu();
        		break;
        	case '0': close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto add_invalid;
 		}
}
//Menampilkan Data
void tampil_univ(){
	FILE *view;
	view = fopen("univ.txt","r");
	int duniv=0;
	system ("cls");
	printf ("ID\t\tNAMA UNIVERSITAS\tALAMAT UNIVERSITAS\tRANGKING\tTAHUN BERDIRI\tAKREDITASI\n");
	while (fscanf (view,"%d;%[^;];%[^;];%d;%d;%[^;];\n",&tambah.kode,tambah.namauniversitas,tambah.alamat,&tambah.rangking,&tambah.tahun,tambah.akreditasi)!=EOF){
		printf("%d\t\t%s\t\t\t%s\t\t%d\t\t%d\t\t%s\t\t\n",tambah.kode,tambah.namauniversitas,tambah.alamat,tambah.rangking,tambah.tahun,tambah.akreditasi);
		duniv++;
	}
	printf ("\nJumlah Data Universitas : %d",duniv);
	fclose(view);
	if(duniv==0){
		system("cls");
		printf ("\nData Kosong ! \n");
	}list_invalid:
    printf("\n\nEnter 1 untuk menu utama dan 0 untuk keluar : ");
    switch(getch()){
    	case '1': menu();
        	break;
        case '0': close();
        	break;
        default:printf("\nMaaf Kesalahan Input !");
        	getche();
        	goto list_invalid;
 	}
}
//Mencari Data
void cari_univ(){
	FILE *ptr;
	int test=0;
	system("cls");
	ptr=fopen("univ.txt","r");
	system("cls");
	printf("Input Kode Universitas : ");
	scanf("%d", &cek.kode);
	while(fscanf (ptr,"%d;%[^;];%[^;];%d;%d;%[^;];\n",&tambah.kode,tambah.namauniversitas,tambah.alamat,&tambah.rangking,&tambah.tahun,tambah.akreditasi)!=EOF){
		if(tambah.kode==cek.kode){
			test=1;
			printf ("\nKode Universitas [%d]",tambah.kode);
			printf("\nNama Universitas\t\t: %s",tambah.namauniversitas);
			printf("\nAlamat Universitas\t\t: %s",tambah.alamat);
			printf("\nRangking Universitas\t\t: %d",tambah.rangking);
			printf("\nTahun Berdiri Universitas\t: %d",tambah.tahun);
			printf("\nAkreditasi Universitas\t\t: %s",tambah.akreditasi);
		}
	}
	fclose(ptr);
	if(test!=1){
		system("cls");
		detail_print:
		printf("\nData tidak ditemukan !\a\a\a");
		detail_invalid:
		printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama dan 2 untuk keluar :");
        switch(getch()){
            case '0': cari_univ();
            	break;
            case '1': menu();
            	break;
            case '2': close();
            	break;
            default:printf("\nMaff Kesalahan Input !");
            	getche();
            	goto detail_invalid;
        }
	}else{
		detail_valid:
		printf("\n\n\nInput 1 untuk ke menu utama dan 0 untuk keluar :");
        switch(getch()){
        	case '1': menu();
       			break;
       		case '0': close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto detail_valid;
       	}
    }

}
//Menghapus Data
void hapus_univ(){
	FILE *lama, *baru;
	int test=0;
	lama = fopen("univ.txt","r");
	baru = fopen("baru.txt","w");
	system("cls");
	printf("Input Kode Universitas yang akan di hapus : ");
	scanf("%d", &hapus.kode);
	while(fscanf (lama,"%d;%[^;];%[^;];%d;%d;%[^;];\n",&tambah.kode,tambah.namauniversitas,tambah.alamat,&tambah.rangking,&tambah.tahun,tambah.akreditasi)!=EOF){
		if(tambah.kode != hapus.kode){
			fprintf(baru,"%d;%s;%s;%d;%d;%s;\n",tambah.kode,tambah.namauniversitas,tambah.alamat,tambah.rangking,tambah.tahun,tambah.akreditasi);
		}else{
			test++;
			printf("\nData Universitas Kode : %d dengan Nama : %s\n",tambah.kode,tambah.namauniversitas);
			printf("\nBerhasil dihapus dari Daftar !");
		}
	}
	fclose(lama);
	fclose(baru);
	remove("univ.txt");
	rename("baru.txt","univ.txt");
		if(test==0){
            printf("\nData tidak ditemukan !\a\a\a");
            erase_invalid:
            printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama and 2 untuk keluar :");
			switch(getch()){
            	case '0': hapus_univ();
            		break;
            	case '1': menu();
            		break;
            	case '2': close();
            		break;
            	default:printf("\nMaaf Kesalahan Input !");
            		getche();
            		goto erase_invalid;
			}
    }else{
    	erase_valid:
		printf("\nInput 1 untuk ke menu utama and 0 untuk keluar :");
        switch(getch()){
       		case '1': menu();
       			break;
       		case '0': close();
       			break;
       		default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto erase_valid;
        }
    }
}
//Mengedit Data
void edit_univ(){
	int pilih,test=0;
	FILE *lama,*baru;
	lama = fopen("univ.txt","r");
	baru = fopen ("baru.txt","w");
	system("cls");

	printf ("Masukan Kode Universitas : ");
	scanf ("%d",&cek.kode);
	while(fscanf (lama,"%d;%[^;];%[^;];%d;%d;%[^;];\n",&tambah.kode,tambah.namauniversitas,tambah.alamat,&tambah.rangking,&tambah.tahun,tambah.akreditasi)!=EOF){
		if(tambah.kode == cek.kode){
			test=1;
			ganti:
				printf("\nKode : %d dimiliki Universitas dengan Nama : %s",tambah.kode,tambah.namauniversitas);
				printf("\n\nData yang akan diganti : ");
				printf("\n[1]. Nama Universitas");
				printf("\n[2]. Alamat");
				printf("\n[3]. Rangking");
				printf("\n[4]. Tahun Berdiri");
				printf("\n[5]. Akreditasi");
				printf("\nInput Pilihan : ");
				scanf("%d",&pilih);
				if(pilih == 1){
					printf ("\nMasukan Data Nama Universitas Baru : ");fflush(stdin);
					scanf ("%[^\n]",cek.namauniversitas);
					strcpy(tambah.namauniversitas,cek.namauniversitas);
						fprintf(baru,"%d;%s;%s;%d;%d;%s;\n",tambah.kode,tambah.namauniversitas,tambah.alamat,&tambah.rangking,&tambah.tahun,tambah.akreditasi);
					printf ("\nPerubahan Sudah Disimpan !");
				}else if (pilih == 2){
					printf("\nMasukan Data Alamat Universitas Baru : ");fflush(stdin);
					scanf ("%[^\n]",cek.alamat);
					strcpy(tambah.alamat,cek.alamat);
						fprintf(baru,"%d;%s;%s;%d;%d;%s;\n",tambah.kode,tambah.namauniversitas,tambah.alamat,&tambah.rangking,&tambah.tahun,tambah.akreditasi);
					printf ("\nPerubahan Sudah Disimpan !");
				}else if (pilih == 3){
					printf ("\nMasukan Data Rangking Baru : ");
					scanf ("%d",&cek.rangking);
					tambah.rangking = cek.rangking;
                        fprintf(baru,"%d;%s;%s;%d;%d;%s;\n",tambah.kode,tambah.namauniversitas,tambah.alamat,&tambah.rangking,&tambah.tahun,tambah.akreditasi);
					printf ("\nPerubahan Sudah Disimpan !");
				}else if (pilih == 4){
					printf ("\nMasukan Data Tahun Berdiri Baru : ");
					scanf ("%d",&cek.tahun);
					tambah.tahun = cek.tahun;
                        fprintf(baru,"%d;%s;%s;%d;%d;%s;\n",tambah.kode,tambah.namauniversitas,tambah.alamat,&tambah.rangking,&tambah.tahun,tambah.akreditasi);
					printf ("\nPerubahan Sudah Disimpan !");
				}else if (pilih == 5){
					printf ("\nMasukan Data Akreditasi Baru : ");fflush(stdin);
					scanf ("%[^\n]",cek.akreditasi);
					strcpy(tambah.akreditasi,cek.akreditasi);
                        fprintf(baru,"%d;%s;%s;%d;%d;%s;\n",tambah.kode,tambah.namauniversitas,tambah.alamat,&tambah.rangking,&tambah.tahun,tambah.akreditasi);
					printf ("\nPerubahan Sudah Disimpan !");
				}else{
					printf("\n\nInput Anda Salah !");
					getche();
					goto ganti;
				}
		}else{
			fprintf(baru,"%d;%s;%s;%d;%d;%s\n",tambah.kode,tambah.namauniversitas,tambah.alamat,&tambah.rangking,&tambah.tahun,tambah.akreditasi);
		}
	}
    fclose(lama);
	fclose(baru);
	remove("univ.txt");
	rename("baru.txt","univ.txt");
	if(test!=1){
		system("cls");
        printf("\nData tidak ditemukan !\a\a\a");
        edit_invalid:
        printf("\nInput 0 untuk mencoba lagi, 1 untuk ke menu utama dan 2 untuk keluar :");
        switch(getch()){
            case '0': edit_univ();
            	break;
            case '1': menu();
            	break;
            case '2': close();
            	break;
            default:printf("\nMaaf Kesalahan Input !");
            	getche();
            	goto edit_invalid;
        }
    }
    else{
    	edit_valid:
		printf("\n\n\nInput 1 untuk ke menu utama dan 0 untuk keluar :");
        switch(getch()){
        	case '1': menu();
        		break;
        	case '0': close();
        		break;
        	default:printf("\nMaaf Kesalahan Input !");
        		getche();
        		goto edit_valid;
        }
    }
}
//Menutup Program
void close(){
}

