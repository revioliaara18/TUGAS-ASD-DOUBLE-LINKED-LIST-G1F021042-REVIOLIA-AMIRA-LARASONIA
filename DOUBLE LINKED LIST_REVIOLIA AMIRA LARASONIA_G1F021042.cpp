#include<iostream>
using namespace std;

struct Tanggal_Lahir{
  string Bulan;
  int Tanggal, Tahun;
  
  Tanggal_Lahir*prev;
  Tanggal_Lahir*next;
};
  Tanggal_Lahir*head,*tail,*cur,*newNode,*del, *before;

void createDoubleLinkedList(int Tanggal,string Bulan, int Tahun){
	head = new Tanggal_Lahir();
	head->Tanggal=Tanggal;
	head->Bulan=Bulan;
	head->Tahun=Tahun;
	head->prev=NULL;
	head->next=NULL;
	tail=head;
}
	int countDoubleLinkedList(){
		cur=head;
		int jumlah=0;
		while(cur!=NULL){
			jumlah++;
			cur=cur->next;
		}
		return jumlah;
}
void addFirst(int Tanggal,string Bulan, int Tahun){
	newNode = new Tanggal_Lahir();
	newNode->Tanggal=Tanggal;
	newNode->Bulan=Bulan;
	newNode->Tahun=Tahun;
	newNode->next=head;
	head=newNode;
}
void addLast(int Tanggal,string Bulan, int Tahun){
	newNode = new Tanggal_Lahir();
	newNode->Tanggal=Tanggal;
	newNode->Bulan=Bulan;
	newNode->Tahun=Tahun;
	newNode->next=NULL;
	tail->next=newNode;
	tail=newNode;	
}
void addMiddle(int Tanggal, string Bulan, int Tahun,int posisi){
	newNode=new Tanggal_Lahir();
	newNode->Tanggal=Tanggal;
	newNode->Bulan=Bulan;
	newNode->Tahun=Tahun;
	cur=head;
	int nomor=1;
	while (nomor < posisi-1){
		cur=cur->next;
		nomor++;
	}
	newNode->prev=cur;
	cur->next=newNode;
	}

void DeleteFirst(){
	
	del=head;
	head=head->next;
	head->prev=NULL;
	delete del;
}
void DeleteLast(){
	del= tail;
	cur= head;
	while(cur->next != tail){
		cur=cur->next;
	}
	tail=cur;
	tail=tail->prev;
	tail->next=NULL;
	delete del;
}

void DeleteMiddle(int posisi){
	if(posisi < 1||posisi > countDoubleLinkedList() ){
		cout<<"Posisi diluar jangkauan"<<endl;
	}else if(posisi==1||posisi== countDoubleLinkedList() ){
		cout <<"Posisi Bukan Posisi Tengah"<<endl;
	}else{
	int nomor=1;
		cur=head;
	while(nomor<=posisi){
		if(nomor== posisi -1){
			before=cur;				
			}
		if(nomor == posisi){
			del=cur;
			}
		cur= cur ->next;
		nomor++;
		}
		del = cur->next;	
		delete del;
	}
}

void printDoubleLinkedList(){
	cout<<"Jumlah data ada:"<< countDoubleLinkedList()<< endl;
	cur=head;
	while(cur!=NULL){
		cout<<"Tanggal Lahir:"<<cur->Tanggal<<endl;
		cout<<"Bulan Lahir:"<<cur->Bulan<<endl;
		cout<<"Tahun Lahir:"<<cur->Tahun<<endl;
		
		cur=cur->next;
	}
}
int main (){

  createDoubleLinkedList(1,"April", 2003);
  printDoubleLinkedList();
  
  cout<<"\n\n"<<endl;
  addFirst(11,"Maret",2004);
  printDoubleLinkedList();
  cout<<"\n\n"<<endl;
  

  addLast(19,"Desember",2003);
  printDoubleLinkedList();
  cout<<"\n\n"<<endl;
  
  addMiddle(9,"Januari",2003,2);
  printDoubleLinkedList();
  cout<<"\n\n"<<endl;
  
  DeleteFirst();
  printDoubleLinkedList();
  cout<<"\n\n"<<endl;
  
  addLast(06,"Februari", 2021);
  printDoubleLinkedList();
  cout<<"\n\n"<<endl;
  
  DeleteLast();
  printDoubleLinkedList();
  cout<<"\n\n"<<endl;
  
  cout<<"\n\n"<<endl;
  
  DeleteMiddle(1);
  printDoubleLinkedList();
  cout<<"\n\n"<<endl;
  
}
