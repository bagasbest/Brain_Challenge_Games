#include <bits/stdc++.h>  // SEBUAH LIBRARY YANG BERISI KUMPULAN LIBRARY STANDAR
#include <windows.h> // UNTUK SYSTEM("CLS")
#include <fstream> // EKSTERNAL

using namespace std;

typedef char infotype;
typedef struct TElmtList *address;
typedef struct TElmtList{
        infotype info;
        address next;
}ElmtList;

typedef struct {
        address head;
        address tail;
}Queue;

/////////////////////SELEKTOR//////////////////////////
#define Head(Q) (Q).head
#define Tail(Q) (Q).tail
#define Next(Q) (Q)->next
#define Info(Q) (Q)->info
#define InfoHead(Q) (Q).head->info

void CreateEmpty(Queue *Q){
     Head(*Q) = NULL;
     Tail(*Q) = NULL;
}

bool IsEmpty(Queue Q){
    return (Head(Q) == NULL && Tail(Q) == NULL);
}

address Alokasi(infotype X){
        address Q = address(malloc(sizeof(ElmtList)));

        if(Q != NULL){
            Info(Q) = X;
            Next(Q) = NULL;
        }
        return Q;
}

void Dealokasi(address P){
     free (P);
}

void Enqueue(Queue *Q, infotype X){
        address P = Alokasi(X);

        if(P != NULL){
            if(IsEmpty(*Q)){
                Head(*Q) = P;
                Tail(*Q) = P;
            }else{
                Next(Tail(*Q)) = P;
                Tail(*Q) = P;
            }
        }
}

void Dequeue(Queue *Q, infotype *X){
     if(!IsEmpty(*Q)){
        address P = Head(*Q);
        *X = Info(P);

        if(Head(*Q)==Tail(*Q)){
        	Head(*Q) = NULL;
        	Tail(*Q) = NULL;
        	Dealokasi(P);
        }
        else{
		
            Head(*Q) = Next(Head(*Q));
            Next(P) = NULL;
            Dealokasi(P);
        }
     }
}

void PrintInfo(Queue Q){
     address P = Head(Q);
     while (Next(P) != NULL){
            cout<<Info(P)<<" ";
            P = Next(P);
     }
     cout<<Info(P);
}

int counter(Queue Q){ // this procedure to count * in every element
    int sum=0;

    while (Head(Q) != NULL){
        if(InfoHead(Q) == '*')
        sum=sum+1;
        Head(Q) = Next(Head(Q));
    }
    return sum;
}

void tab(){ //basic tab
	for(int t=0; t<3; t++){
		cout<<"\t";
	}
}

void loading (Queue Q){ // loading screen
tab(); cout<<"Time Limit : ";
     for(int i=5; i>0; i--){
     	cout<<" . ";
     	Sleep(1000);
     }
	}


void trivia(){
     string kata[4] = {"  C++ adalah bahasa yang dikembangkan oleh Bjarne Stroustrup, merupakan pengembangan dari bahasa C pada tahun 1970-an.",
                       "  Sewaktu muda Gates dikenal gemar mengotak-atik sistem komputer. Termasuk, bersama tiga rekannya, untuk mendapatkan akses gratisan.",
                       "  Larry Page dan Sergey Brin dulunya tidak akur, namun dikarenakan memiliki persamaan visi, akhirnya mereka bekerja sama membuat satu perusahaan yang sekarang menjadi raksasa."
					   ,"  Dr Eng Khoirul Anwar adalah seorang ilmuwan asli Indonesia penemu teknologi 4G dengan memanfaatkan gaya tarik energi disekitarnya"};

     int ran = rand()%4;
     if(ran == 0){
		cout<<kata[0];
	 }else if(ran == 1){
        cout<<kata[1];
     }else if(ran == 2){
		cout<<kata[2];
	 }else if(ran == 3){
		cout<<kata[3];
	 }

}

void loading_bar (){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    system("color 0f");
     for(int j=0; j<15; j++){
        cout<<endl;
     }
      cout<<"NOW LOADING"<<endl;
     trivia(); cout<<endl<<endl;

     tab(); for (int i=0; i<72; i++){
        SetConsoleTextAttribute(h, FOREGROUND_RED| FOREGROUND_INTENSITY);
        cout<<"|";
        Sleep(70);
     }

}

void menu(){
	cout<<"\n\n\n\n\n\n";
	system("color 0f");
    	tab(); cout<<"                      ~~=====================~~ \n";
        tab(); cout<<"~~================~~'| GAME BRAIN CHALLENGE    |'~~===============~~\n";
        tab(); cout<<"|                     ~~=====================~~                     | \n";
        tab(); cout<<"|                                                                   | \n";
        tab(); cout<<"|                                                                   | \n";
        tab(); cout<<"|   [1] MAIN                                                        | \n";
        tab(); cout<<"|                                                                   | \n";
        tab(); cout<<"|   [2] PAPAN SKOR                                                  | \n";
        tab(); cout<<"|                                                                   | \n";
        tab(); cout<<"|   [3] KELUAR                                                      | \n";
        tab(); cout<<"|                                                                   | \n";
        tab(); cout<<"|                                                                   | \n";
        tab(); cout<<"|                    ~~=====================~~                      | \n";
		tab(); cout<<"~~===============~~'~|  CREATED BY KELOMPOK   |~'~~===============~~\n";
		tab(); cout<<"                     ~~=====================~~                  \n";
}

struct scoreboard {
    string nama;
    int skor;
};

int main(){
    bool mati = false; //to calculate if answer always correct
    Queue Q[100];
    infotype X;

    int bintang,i=0,w=1;
    char pilihan;
    char kar[6] = {'+','-','*','/','@','$'};

    srand(time(0));
    scoreboard x[5];
    string pemain, temp2, temp3;
    int j,nilai,temp, temp1;

    do{
        menu:
        system("cls");
        loading_bar ();
        system("cls");
    	tab(); menu();
        tab(); cout<<"Pilihan : "; cin>>pilihan;

            switch (pilihan){
                    case '1'    : { system("cls");
                                    cout<<"\n\n";
                                    tab(); cout<<"USERNAME : ";
                                    cin >> pemain;
                    				cout<<"\n\n";
									loading_bar ();
									system("color 0f");
                                    for(i=0; i<3; i++){ //TIGA SCENE PERTAMA
                                    	system("cls");
                                    	CreateEmpty(&Q[i]);
                                    	cout<<"\n\n";
                                      	tab(); cout<<"   Scene "<<i+1<<"\n\n\n";


                                        	for(int j=0; j<15; j++){
                                            	Enqueue(&Q[i],kar[rand()%6]);
											}

											tab(); cout<<"                 ~~==============================~~                   \n";
											tab(); cout<<"~~==========~~'~|   ";PrintInfo(Q[i]); cout<<"  |~'~~==========~~\n";
											tab(); cout<<"                 ~~==============================~~                  \n\n\n";	 //time.h, coutdown timer
            								tab(); cout<<"   Note: ingatlah jumlah * yang muncul pada scene ini \t"<<endl;
            								loading(Q[i]);
                                  	}



								  	while(!mati){
                                  	    system("cls");
                                               cout<<"\n\n\n";
                                    	       tab(); cout<<"   Jumlah * yang muncul pada scene "<<i-2<<endl;
											   tab(); cout<<"   jawab : "; cin>>bintang; cout<<endl;


										if(bintang == counter(Q[i-3])){
											system("cls");
                                        	CreateEmpty(&Q[i]);


	 											if(w%3==0){
												   int ran = 1+rand()%9;
	 													if(ran == 1){
															system("color f2");
														}
														else if(ran == 2){
															system("color f0");
														}
														else if(ran == 3){
															system("color e0");
														}
														else if(ran == 4){
															system("color cf");
														}
														else if(ran == 5){
															system("color 02");
														}
														else if(ran == 6){
															system("color b4");
														}
														else if(ran == 7){
															system("color 5f");
														}
														else if(ran == 8){
															system("color 8e");
														}
														else if(ran == 9){
															system("color 3e");
														}
													}

                                        	        cout<<"\n\n";

                                        		    tab(); cout<<"   Scene "<<i+1<<"\n\n\n";

                                                for(int j=0; j<15; j++){
                                            	   Enqueue(&Q[i],kar[rand()%6]);
											    }
											     tab(); cout<<"                 ~~==============================~~                   \n";
                                                 tab(); cout<<"~~==========~~'~|   ";PrintInfo(Q[i]); cout<<"  |~'~~==========~~\n";
                                                 tab(); cout<<"                 ~~==============================~~                  \n\n\n";	 //time.h, coutdown timer
            								     tab(); cout<<"   Note: ingatlah jumlah * yang muncul pada scene ini \t"<<endl;
									  		     loading(Q[i]);
									  		     w++;


                                    	}else{
                                    		system("cls");
                                    		system("color f2");
											cout<<"\n\n";

    										tab(); cout<<"                 ~~=====================~~ \n";
        									tab(); cout<<"~~===========~~'| GAME BRAIN CHALLENGE    |'~~==========~~\n";
        									tab(); cout<<"|                ~~=====================~~                | \n";
        									tab(); cout<<"|                                                         | \n";
        									tab(); cout<<"|                   Jawaban anda salah!                   | \n";
        									tab(); cout<<"|                                                         | \n";
        									tab(); cout<<"|                                                         | \n";
        									tab(); cout<<"|    Pada Scene "<<i-2<<"                                         | \n";
        									tab(); cout<<"|                                                         | \n";
        									tab(); cout<<"|               ";PrintInfo(Q[i-3]);cout<<"             | \n";
        									tab(); cout<<"|                                                         | \n";
        									tab(); cout<<"|        jumlah * ada : "<<counter(Q[i-3])<<"                                 | \n";
        									tab(); cout<<"|        Skor Anda    : "<<i-3<<"                                 | \n";
        									tab(); cout<<"|                                                         | \n";
        									tab(); cout<<"|                TERIMA KASIH TELAH BERMAIN               | \n";
        									tab(); cout<<"|                                                         | \n";
        									tab(); cout<<"|                                                         | \n";
        									tab(); cout<<"|                ~~=====================~~                | \n";
											tab(); cout<<"~~=======~~'~~ |    CREATED BY KELOMPOK   | ~~'~~=======~~\n";
											tab(); cout<<"                 ~~=====================~~ \n\n";

                                            goto PAPAN;

                                        }
                                    	Dequeue (&Q[i-3], &X); // menghapus scene yang tidak digunakan (i-3)
                                    	i++;
                                  	}

                                        PAPAN:
                                  	{nilai= i-3;

                                    ifstream filea("nama.txt",ios::in);
                                    ifstream fileb("skor.txt",ios::in);

                                    i=0;
                                    while (!filea.eof()){
                                        filea >> x[i].nama;
                                        i++;
                                    }

                                    i=0;
                                    while (!fileb.eof()){
                                        fileb >> x[i].skor;
                                        i++;
                                    }

                                    filea.close();
                                    fileb.close();

                                    for (int i=0; i<5; i++) {
                                        if (nilai != 0) {
                                            if (nilai >= x[i].skor) {
                                                temp = x[i].skor;
                                                j=i;
                                                x[i].skor = nilai;
                                                for (int i = j+1; i<5; i++) {
                                                    temp1 =  x[i].skor;
                                                    x[i].skor = temp;
                                                    temp = temp1;
                                                }
                                                break;
                                            }
                                        }
                                    }
                                     for (int i=0; i<5; i++) {
                                        if (nilai != 0) {
                                            if (nilai >= x[i].skor) {
                                                temp2 = x[i].nama;
                                                j=i;
                                                x[i].nama = pemain;
                                                for (int i = j+1; i<5; i++) {
                                                    temp3 =  x[i].nama;
                                                    x[i].nama = temp2;
                                                    temp2 = temp3;
                                                }
                                                break;
                                            }
                                        }
                                    }

                                    ofstream file1, file2;
                                    file1.open("nama.txt");
                                    file2.open("skor.txt");

                                    for (int i=0; i<5; i++) {
                                      file1 << x[i].nama << endl;
                                      file2 << x[i].skor << endl;
                                    }

                                    file1.close();
                                    file2.close();


                                    char sekor;
                                   tab(); cout<<" [0] UNTUK MASUK KE PAPAN SKOR  : "; cin>>sekor;

                                    if(sekor == '0'){
                                        goto skor;
                                    }else{
                                        goto skor;
                                    }
                                }


                                  	break;
                    }


                    case '2'    : { skor:
                                    system("cls");
                                    ifstream filea("nama.txt",ios::in);
                                    ifstream fileb("skor.txt",ios::in);

                                    i=0;
                                    while (!filea.eof()){
                                        filea >> x[i].nama;
                                        i++;
                                    }

                                     i=0;
                                    while (!fileb.eof()){
                                        fileb >> x[i].skor;
                                        i++;
                                    }
                                    filea.close();
                                    fileb.close();

                                    cout<<"\n\n\n";
                                    tab(); cout<<"                 ~~================~~                \n";
                                    tab(); cout<<"~~=======~~'~~ |    HALL  OF  FAME   | ~~'~~=======~~\n";
                                    tab(); cout<<"                 ~~================~~                \n\n";
                                    tab(); cout<<"         NAMA   "<< "       "<<   "\t\t SKOR"   <<"\n\n";
                                    for (int i=0; i<5; i++) {
                                        tab();cout <<"\t"<< x[i].nama<<"       "<<"\t\t"<< x[i].skor << endl;
                                        }cout<<"\n\n";

                                        char balik2;
                                        tab(); cout<<"[0] KEMBALI KE MENU : "; cin>>balik2;

                                        if(balik2 == 0 ){
                                            goto menu;
                                        }else{
                                            goto menu;
                                        }


                                    break;
                                  }

                    case '3'    : return 0;
                                  break;


                    default   : break;
            }

    }while(pilihan != '3');
}
