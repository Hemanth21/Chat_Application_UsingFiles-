#include "iostream"
#include "algorithm"
#include "fstream"
using namespace std;
int user=0;
int main();
int menu(int u);
int ismember(int u,string s);


int Directr(int u){
  fstream fp;
  string message,name,temp,namei;
  int s,st,r;
  fp.open("messages.txt");
  while(!fp.eof()){
    fp >> r;
    fp >> s;
    fp >> message;
    fp >> st;
    fp >> namei;
    if(fp.eof())break;
    if(r==u && r!=0)
      cout << "s->" << s << ":" <<message  << ".\n";
  }
  fp.close();
  return 0;
}

int Groupr(int u){
  fstream fp;
  string r,message,name,namei;
  int s,st;
  cout << "Enter the Group: ";
  cin >> name;
  if(ismember(u,name+".txt")){
  fp.open("messages.txt");
  while(!fp.eof()){
    fp >> r;
    fp >> s;
    fp >> message;
    fp >> st;
    fp >> namei;
    if(fp.eof())break;
    if(name==namei){
      cout << "s:" << s << "-"<<  message  << ".\n";
    }
  }
  }
  fp.close();
  return 0;
}


int isBlocked(int u,int s){
  ifstream fp;
  int uu,a,m,st,b;
  fp.open("contacts.txt");
  while(!fp.eof()){
    fp >> uu;
    fp >> a;
    fp >> m;
    fp >> st;
    fp >> b;
    if(fp.eof())break;
    if(uu==u && s==a && st==1)
      return 1;
  }
  fp.close();
  return 0;
}


int Groups(int u){
  ofstream fp;
  string group;;
  string message;
  cout << "Enter Group Name : ";
  cin >> group;
  if(ismember(u,group+".txt")){
  cout << "Enter the message:";
  cin >> message;
  fp.open("messages.txt",ios::app);
  fp << 0 << " ";
  fp << u   << " ";
  fp << message << " ";
  fp << 0 << " ";
  fp << group << "\n";
  }
  fp.close();
  return 0;
}


int Directs(int u){
  ofstream fp;
  int num;
  string message;
  cout << "Enter Recievers Number: ";
  cin >> num;
  cout << "Enter the message:";
  cin >> message;
  if(!isBlocked(u,num)){
  fp.open("messages.txt",ios::app);
  fp << num << " ";
  fp << u   << " ";
  fp << message << " ";
  fp << 0 << " ";
  fp << "basd" << " \n";
  fp.close();
  }

  return 0;
}

int messagesM(int u){
  while(1){
  system("cls");
  int n;
  cout << "1.Send Personal Messages\n2.Send Group Message\n3.View Messages\n4.View group Messages\n5.Main Menu\n";
  cin >> n;
  switch(n){
    case 1:Directs(u);break;
    case 2:Groups(u);break;
    case 3:Directr(u);break;
    case 4:Groupr(u);break;
    case 5:menu(u);break;
    default:cout << "Invalid\n";
  }
  system("pause");
}
return 0;
}


int isStar(int u,string s){
  ifstream fp;
  int uu,a,m,st;
  fp.open(s);
  ofstream fp1;
  fp1.open("temp.txt",ios::app);
  while(!fp.eof()){
    fp >> uu;
    fp >> a;
    fp >> m;
    fp >> st;
    if(fp.eof())break;
    if(uu==u)st=!st;
    fp1 << uu << " ";
    fp1 << a << " ";
    fp1 << m << " ";
    fp1 << st << "\n";
  }
  fp.close();
  fp1.close();
    remove(s.c_str());
    rename("temp.txt",s.c_str());
  return 0;
}

int isMute(int u,string s,int c){
  ifstream fp;
  int uu,a,m,st;
  fp.open(s);
  ofstream fp1;
  fp1.open("temp.txt",ios::app);
  while(!fp.eof()){
    fp >> uu;
    fp >> a;
    fp >> m;
    fp >> st;
    if(fp.eof())break;
    if(m==0 && uu==u && c==0){
    fp.close();
    return 1;
  }else if( c==1){
    if(uu==u)m=!m;
    fp1 << uu << " ";
    fp1 << a << " ";
    fp1 << m << " ";
    fp1 << st << "\n";
  }
  }
  fp1.close();
  fp.close();
  if(c){
    remove(s.c_str());
    rename("temp.txt",s.c_str());
  }
  return 0;
}

int isAdmin(int u,string s,int c){
  ifstream fp;
  int uu,a,m,st,num;
  if(c==1){
    cout << "Enter the contact: ";
    cin >> num;
  }
  fp.open(s);
  ofstream fp1;
  fp1.open("temp.txt",ios::app);
  while(!fp.eof()){
    fp >> uu;
    fp >> a;
    fp >> m;
    fp >> st;
    if(fp.eof())break;
    if(a==1 && uu==u && c==0){
    fp.close();
    return 1;
  }else if( c==1){
    if(uu==num)a=!a;
    fp1 << uu << " ";
    fp1 << a << " ";
    fp1 << m << " ";
    fp1 << st << "\n";
  }
  }
  fp1.close();
  fp.close();
  if(c){
    remove(s.c_str());
    rename("temp.txt",s.c_str());
  }
  return 0;
}

int ismember(int u,string s){
   ifstream fp;
   int uu,a,m,st;
   fp.open(s);
   while(!fp.eof()){
     fp >> uu;
     fp >> a;
     fp >> m;
     fp >> st;
     if(fp.eof())break;
     if(uu==u ){
     fp.close();
     return 1;
   }
   }
   fp.close();
   return 0;
}

int DeleteCon(int u,string s){
  int uu,a,m,st;
  ofstream fp;
  fp.open("temp.txt",ios::app);
  ifstream fp1;
  fp1.open(s);
  while(!fp1.eof()){
    fp1 >> uu;
    fp1 >> a;
    fp1 >> m;
    fp1 >> st;
    if(fp1.eof())break;
    if(uu!=u){
      fp << uu << " ";
      fp << a << " ";
      fp << m << " ";
      fp << st << "\n";
    }
  }
  fp.close();
  fp1.close();
  remove(s.c_str());
  rename("temp.txt",s.c_str());
  return 0;
}


int AddDeleteGm(int u){
  string s;
  int num;
  cout << "Enter Group Name: ";
  cin >> s;
  s=s+".txt";
  if(isAdmin(u,s,0)){
    cout << "Enter Contact Number:";
    cin >> num;
    if((ismember(num,s)))DeleteCon(num,s);
    else{
      ofstream fp;
      fp.open(s,ios::app);
      fp << num << " ";
      fp << 0 << " ";
      fp << 0 << " ";
      fp << 0 << "\n";
      fp.close();
    }
  }
  return 0;
}


int delG(int u){
  string s;
  int uu,a,m,st;
  cout << "Enter Group Name: ";
  cin >> s;
  s=s+".txt";
  int v1=isAdmin(u,s,0);
  if(v1){
  remove(s.c_str());
  }
  return 0;
}

int viewG(int u){
  string s;
  int uu,a,m,st;
  cout << "Enter Group Name: ";
  cin >> s;
  s=s+".txt";
  ifstream fp;
  fp.open(s);
  if(ismember(u,s)){
  while(!fp.eof()){
    fp >> uu;
    fp >> a;
    fp >> m;
    fp >> st;
    if(fp.eof())break;
    cout << uu  << "  ";
    if(a==1)cout << "Admin" ;
    cout << "\n";
  }
   fp.close();
 }
  return 0;
}

int CGroup(int u){
  string gname;
  ofstream fp;
  cout << "Enter Group Name: ";
  cin >> gname;
  gname=gname+".txt";
  fp.open(gname,ios::app);
  fp << u << " ";
  fp << 1 << " ";
  fp << 0 << " ";
  fp << 0 << "\n";
  fp.close();
  return 0;
}

int ExitGroup(int u,string s){
  ifstream fp;
  fp.open(s);
  int uu,a,m,st;
  int count=0;
  if(isAdmin(u,s,0)){
  while(!fp.eof()){
    fp >> uu;
    fp >> a;
    fp >> m;
    fp >> st;
    if(fp.eof())break;
    if(a==1)count++;
  }
  fp.close();
  if(count>1){DeleteCon(u,s);}
  else{remove(s.c_str());}
  }
  return 0;
}

int Gmenu(int u){
  int n;
  string gname;
  while(1){
    system("cls");
    cout << "1.Create Group\n2.View Group\n3.Delete Group\n4.ADD-Delete Members\n5.MuteUnmute\n6.StarUnstar\n7.AddDelete Admin\n8.Exit Group\n9.Main Menu\n";
    cin >> n;
    switch(n){
      case 1:CGroup(u);break;
      case 2:viewG(u);break;
      case 3:delG(u);break;
      case 4:AddDeleteGm(u);break;
      case 5:cout << "Enter Group Name: ";
             cin >> gname;
             gname=gname+".txt";
             isMute(u,gname,1);break;
      case 6:cout << "Enter Group Name: ";
             cin >> gname;
             gname=gname+".txt";
             isStar(u,gname);break;
      case 7:cout << "Enter Group Name: ";
             cin >> gname;
             gname=gname+".txt";
             isAdmin(u,gname,1);break;
      case 8:cout << "Enter the group:";
             cin >> gname;
             gname=gname+".txt";
             ExitGroup(u,gname);break;
      case 9:menu(u);break;
      default:cout << "Invalid\n";
    }
    system("pause");
  }
  return 0;
}


int MuteUnmute(int u){
  int m,s,b,cc,tc,n;
  ifstream fp;
  ofstream fp1;
  fp1.open("temp.txt");
  fp.open("contacts.txt");
  cout << "Enter the contact : ";
  cin >> n;
  while(!fp.eof()){
    fp >> cc;
    fp >> tc;
    fp >> m;
    fp >> b;
    fp >> s;
    if(fp.eof())break;
    if(u==cc && tc==n)
        m=!m;
    fp1 << cc << " ";
    fp1 << tc << " ";
    fp1 << m << " ";
    fp1 << b << " ";
    fp1 << s << "\n";
  }
  fp.close();
  fp1.close();
  remove("contacts.txt");
  rename("temp.txt","contacts.txt");
  return 0;
}



int BlockUnblock(int u){
  int m,s,b,cc,tc,n;
  ifstream fp;
  ofstream fp1;
  fp1.open("temp.txt");
  fp.open("contacts.txt");
  cout << "Enter the contact : ";
  cin >> n;
  while(!fp.eof()){
    fp >> cc;
    fp >> tc;
    fp >> m;
    fp >> b;
    fp >> s;
    if(fp.eof())break;
    if(u==cc && tc==n)
        b=!b;
    fp1 << cc << " ";
    fp1 << tc << " ";
    fp1 << m << " ";
    fp1 << b << " ";
    fp1 << s << "\n";
  }
  fp.close();
  fp1.close();
  remove("contacts.txt");
  rename("temp.txt","contacts.txt");
  return 0;
}


int StarUnstar(int u){
  int m,s,b,cc,tc,n;
  ifstream fp;
  ofstream fp1;
  fp1.open("temp.txt");
  fp.open("contacts.txt");
  cout << "Enter the contact : ";
  cin >> n;
  while(!fp.eof()){
    fp >> cc;
    fp >> tc;
    fp >> m;
    fp >> b;
    fp >> s;
    if(fp.eof())break;
    if(u==cc && tc==n)
        s=!s;
    fp1 << cc << " ";
    fp1 << tc << " ";
    fp1 << m << " ";
    fp1 << b << " ";
    fp1 << s << "\n";
  }
  fp.close();
  fp1.close();
  remove("contacts.txt");
  rename("temp.txt","contacts.txt");
  return 0;
}

int view(int u){
  fstream fp;
  int cc,tc,m,b,s;
  fp.open("contacts.txt");
  while(!fp.eof()){
    fp >> cc;
    fp >> tc;
    fp >> m;
    fp >> b;
    fp >> s;
    if(fp.eof())break;
    if(cc ==u ){
    cout << tc  << "  ";
    if(s==1)cout << "* ";else cout << "  ";
    if(b==1)cout << "B ";else cout << "  ";
    if(m==1)cout << "M ";else cout << "  ";
    cout << " \n";
  }
  }
  return 0;
}

int Deletec(int u, int n){
  int m,s,b,cc,tc,flag=0;
  ofstream fp;
  ifstream fp1;
  fp1.open("contacts.txt");
  fp.open("temp.txt");
  while(!fp1.eof()){
    fp1 >> cc;
    fp1 >> tc;
    fp1 >> m;
    fp1 >> b;
    fp1 >> s;
    if(fp1.eof())break;
    if(!(u==cc && n==tc)){
      fp << cc << " ";
      fp << tc << " ";
      fp << m << " ";
      fp << b << " ";
      fp << s << "\n";
    }
  }
  fp.close();
  fp1.close();
  remove("contacts.txt");
  rename("temp.txt","contacts.txt");
  return 0;
}

int AddDelete(int u){
  int m,s,b,cc,tc,n,flag=0;
  ifstream fp;
  ofstream fp1;
  cout << "Enter the Contact number:";
  cin >> n;
  fp.open("contacts.txt",ios::app);
  while(!fp.eof()){
    fp >> cc;
    fp >> tc;
    fp >> m;
    fp >> b;
    fp >> s;
    if(fp.eof())break;
    if(cc==u && tc==n){
      flag=1;
      fp.close();
      Deletec(cc,tc);
      break;
    }
  }
  if(!flag){
    fp1.open("contacts.txt",ios::app);
    fp1 << u << " ";
    fp1 << n << " ";
    fp1 << 0 << " ";
    fp1 << 0 << " ";
    fp1 << 0 << "\n";
    fp.close();
    fp1.close();
  }

  return 0;
}

int Contacts(int u){
  int n;
  while(1){
    system("cls");
    cout << "1.Add-Delete\n2.View-Contacts\n3.Star-Unstar\n4.Block-Unbloct\n5.Mute-Unmute\n6.Main Menu\n";
    cin >> n;
    switch(n){
      case 1:AddDelete(u);break;
      case 2:view(u);break;
      case 3:StarUnstar(u);break;
      case 4:BlockUnblock(u);break;
      case 5:MuteUnmute(u);break;
      case 6:menu(0);
      default:cout << "Invalid\n";
    }
    system("pause");
  }
  return 0;
}

int menu(int u){
  int n;
  while(1){
    system("cls");
    cout << "1.Contacts\n2.Groups\n3.Messgaes\n4.logout\n";
    cin >> n;
    switch(n){
      case 1:Contacts(u);break;
      case 2:Gmenu(u);break;
      case 3:messagesM(u);break;
      case 4:user=0;main();
      default:cout << "Invalid Option\n";
    }
    system("pause");
  }
  return 0;
}

int main(){
  int n;
  system("cls");
  cout << "Enter Your Identity: ";
  cin >> n;
  menu(n);
  return 0;
}
