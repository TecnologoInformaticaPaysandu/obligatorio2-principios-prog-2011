#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include <dos.h>

struct lib{ char titulo[30], autor[20], cat[15], codigo[8], estado;
	    int stock, precio;};

void m_principal();
void m_manten();
void m_ventas();
void m_busqueda();
void m_consultas();
void m_altas();
void m_abml();
void p_altcant();
void p_bustitulo();
void p_busqueda(char);
void manten(char);
void error(int, int);

void recuadro(int, int, int, int);
void fondo(int, int, int, int, char);

void main()
{
    const tam=5;
    int opc0=-1, opc1=-1, opc2=-1, j=0, k=0, x=0, w=0;
    int cont=0, c1=0, vez=0, cant=0, venta=0, d=0, m=0, a=0;
    char seg=0, letra1=' ', letra2=' ', letra3=' ';
    char cod[8]={'0'}, titulo[30], cat[15], autor[20];
    lib libro[tam]={'\x0'}, aux;

    struct date f;
    getdate(&f);

    textbackground(1);

    m_principal();     			    //  menu principal
    while(opc0!=0)                          //  opcion 0 finaliza
    {
       cin>>opc0;
       error(opc0,4);

       if(opc0==0)
       {
	  fondo(19,18,21,62,' ');
	  recuadro(19,18,21,62);
	  gotoxy(19,20);
	  cout<<"  Presione cualquier tecla para salir...";
       }

       switch(opc0)
       {
	 case 1:
	   do
	   {
	      m_manten();                //  Menu Mantenimiento de libros
	      cin>>opc1;
	      error(opc1,4);             //  Selecciona opcion m_principal
	      switch(opc1)
	      {
		case 1:
		  do
		  {
		     m_altas();              //  Menu Ingresos de libros
		     cin>>opc2;
		     error(opc2,2);

		     if(opc2==2)
		     {
			do
			{
			   p_altcant();          // pantalla de altas
			   gotoxy(45,21);cout<<" CODIGO 0 SALIR ";
			   for(k=0; k<8; k++)
			       cod[k]='\x0';

			   gotoxy(34,6);gets(cod);
			   if(cod[0]!='0')
			   {
			     cont=0;
			     do{ vez=0;
				 for(x=0; x<tam; x++)
				 {
				    if(strcmpi(cod,libro[x].codigo)==0)
				    {
				       cont++;
				       vez=x;
				       gotoxy(25,10); cout<<"Titulo___: ";
				       gotoxy(25,11); cout<<"Autor____: ";
				       gotoxy(25,12); cout<<"Categoria: ";
				       gotoxy(25,13); cout<<"Precio___: ";
				       gotoxy(25,14); cout<<"Stock____: ";
				       gotoxy(38,10); cout<<libro[vez].titulo;
				       gotoxy(38,11); cout<<libro[vez].autor;
				       gotoxy(38,12); cout<<libro[vez].cat;
				       gotoxy(38,13); cout<<libro[vez].precio;
				       gotoxy(38,14); cout<<libro[vez].stock;
				    }
				 }

				 if(cont==0)
				 {
				    gotoxy(23,18);
				    cout<<"El codigo no existe, intentelo de nuevo";
				    getch();
				    gotoxy(23,18);
				    cout<<"                                       ";
				    gotoxy(34,6);cout<<"          ";
				    gotoxy(34,6);gets(cod);
				    if(cod[0]=='0')
				      seg='s';

				 }
				 else
				 {
				    gotoxy(35,8);cin>>cant;
				    gotoxy(25,18);cout<<"Confirmar [S/N]: ";
				    gotoxy(42,18);cin>>seg;
				    libro[vez].stock=libro[vez].stock+cant;
				    gotoxy(25,18);cout<<"Operacion Exitosa  ";
				    getch();
				    gotoxy(25,18);cout<<"                   ";
				 }

			       }
			     while(cont==0&&cod[0]!='0');
			   }
			   else
			      { seg='s';
				clrscr();
			      }

			}
			while(seg!='s' && seg!='S');
		     }

		     if(opc2==1)
		     {
			do
			{
			   manten('a');
			   gotoxy(17,4);  gets(libro[j].titulo);
			   gotoxy(17,6);  gets(libro[j].autor);
			   gotoxy(17,8);  gets(libro[j].cat);
			   gotoxy(17,10); cin>>libro[j].precio;
			   gotoxy(17,12); cin>>libro[j].stock;
			   gotoxy(5,15);  cout<<"Confirmar [S/N]: ";
			   gotoxy(23,15); cin>>seg;
			   libro[j].estado='A';
			   gotoxy(5,17);
			   vez=1;
			   cant=1;
			   cont=0;
			   cod[0]=libro[j].autor[0];

			   for(k=0; k<20; k++)
			      if(libro[j].autor[k]==' ')
				 cont++;
			   k=0;
			   if(cont!=0)
			   {
			      do{ while(libro[j].autor[k]!=' '&&libro[j].autor[k]!='\x0')
				    k++;
				  while(libro[j].autor[k]==' ')
				    k++;
				  cod[cant]=libro[j].autor[k];
				    cant++;
				}
			      while(cant!=3);
			   }

			   for(k=0; k<30; k++)
			   {
			      if(libro[j].titulo[k]!=' ')
			      {
				 if(vez==1)
				   letra1=libro[j].titulo[k];
				 if(vez==2)
				   letra2=libro[j].titulo[k];
				 if(vez==3)
				 {
				   letra3=libro[j].titulo[k];
				   k=30;
				 }
				 vez++;
			      }

			   }
			   cod[cont+1]=letra1;
			   cod[cont+2]=letra2;
			   cod[cont+3]=letra3;

			   for(k=0; k<tam; k++)
			   {
			      if(strcmpi(cod,libro[k].codigo)==0)
			      {
				if(cod[cont+4]==0)
				   cod[cont+4]=cod[cont+4]+49;
				else
				   cod[cont+4]=cod[cont+4]+1;
			      }
			   }
			   strcpy(libro[j].codigo,cod);
			   cout<<"El codigo del libro es: ";
			   gotoxy(30,17);cout<<libro[j].codigo;
			   gotoxy(5,20);
			   cout<<"Presione una tecla para continuar...";
			   getch();fondo(0,0,25,81,' ');
			   j++;
			}
			while(seg!='s' && seg!='S');
		     }
		     if(opc2==0)
		     {
			fondo(1,1,25,81,' ');
		     }
		  }
		  while(opc2!=0);
		  break;

		case 2:
		  do
		  {
		     manten('b');
		     gotoxy(60,24);cout<<" CODIGO 0 SALIR ";

		     for(k=0; k<8; k++)
			cod[k]='\x0';

		     gotoxy(10,20);cout<<"Ingrese codigo: ";
		     gotoxy(26,20);gets(cod);
		     if(cod[0]!='0')
		     {
		       do{ cont=0;
			   k=0;
			   for(x=0; x<tam; x++)
			   {
			     if(strcmpi(cod,libro[x].codigo)==0)
			     {
				k++;
				cont=x;
				gotoxy(17,4);cout<<libro[x].titulo;
				gotoxy(17,6);cout<<libro[x].autor;
				gotoxy(17,8);cout<<libro[x].cat;
				gotoxy(17,10);cout<<libro[x].precio;
				gotoxy(17,12);cout<<libro[x].stock;
			     }
			   }

			   if(k==0)
			   {
			      gotoxy(10,22);
			      cout<<"Codigo Incorrecto, intentelo de nuevo";
			      getch();
			      fondo(21,9,23,50,' ');
			      fondo(19,25,21,40,' ');
			      gotoxy(26,20);gets(cod);
			      if(cod[0]=='0')
			      {  seg='s';
				 k=1;
				 fondo(2,1,25,81,' ');
			      }

			   }
			   else
			   {
			      gotoxy(5,15);cout<<"Confirmar Baja [S/N]: ";
			      gotoxy(28,15);cin>>seg;
			      libro[cont].estado='B';
			   }
			 }
		       while(k==0&&cod[0]!='0');

		     }
		     else
			 { seg='s';
			   clrscr();
			 }
		  }
		  while(seg!='s' && seg!='S'&& k==0);
		  break;

		case 3:
		  do
		  {
		     manten('m');
		     gotoxy(60,24);cout<<" CODIGO 0 SALIR ";

		     for(k=0; k<8; k++)
			cod[k]='\x0';
		     gotoxy(10,20);cout<<"Ingrese codigo: ";
		     gotoxy(27,20);gets(cod);
		     if(cod[0]!='0')
		     {
			cont=0;

			do{ k=0;
			    for(x=0; x<tam; x++)
			    {
			       if(strcmpi(cod,libro[x].codigo)==0)
			       {
				  k++;
				  cont=x;
				  gotoxy(17,4);  cout<<libro[x].titulo;
				  gotoxy(17,6);  cout<<libro[x].autor;
				  gotoxy(17,8);  cout<<libro[x].cat;
				  gotoxy(17,10); cout<<libro[x].precio;
				  gotoxy(17,12); cout<<libro[x].estado;
			       }
			    }
			    if(k==0)
			    {
			      gotoxy(10,22);
			      cout<<"Codigo Incorrecto, intentelo de nuevo";
			      getch();
			      fondo(21,9,23,50,' ');
			      gotoxy(27,20);cout<<"          ";
			      gotoxy(27,20);gets(cod);
			      if(cod[0]=='0')
			      {	 seg='s';
				 fondo(2,1,25,81,' ');
			      }

			    }
			    else
			    {
			      getch();
			      fondo(4,15,20,60,' ');
			      gotoxy(17,4) ;gets(libro[cont].titulo);
			      gotoxy(17,6) ;gets(libro[cont].autor);
			      gotoxy(17,8) ;gets(libro[cont].cat);
			      gotoxy(17,10);cin>>libro[cont].precio;
			      gotoxy(17,12);cin>>libro[cont].estado;
			      c1=0;
			      cant=1;
			      vez=1;
			      gotoxy(5,20);
			      cout<<"Confirmar Modificacion [S/N]: ";
			      gotoxy(35,20);cin>>seg;

			      for(k=0; k<20; k++)
				if(libro[cont].autor[k]==' ')
				   c1++;

			      for(k=0; k<8; k++)
				  cod[k]='\x0';

			      cod[0]=libro[cont].autor[0];
			      if(c1!=0)
			      {
				 do{ while(libro[cont].autor[k]!=' '&&libro[j].autor[k]!='\x0')
					k++;
				     while(libro[cont].autor[k]==' ' )
					k++;

				     cod[cant]=libro[cont].autor[k];
					cant++;
				   }
				 while(cant!=3);
			      }

			      for(k=0; k<30; k++)
			      {
				 if(libro[cont].titulo[k]!=' ')
				 {
				    if(vez==1)
				      letra1=libro[cont].titulo[k];

				    if(vez==2)
				      letra2=libro[cont].titulo[k];

				    if(vez==3)
				    {
				      letra3=libro[cont].titulo[k];
				      k=30;
				    }
				    vez++;
				 }
			      }

			      cod[c1+1]=letra1;
			      cod[c1+2]=letra2;
			      cod[c1+3]=letra3;

			      for(k=0; k<tam; k++)
			      {
				 if(strcmpi(cod,libro[k].codigo)==0)
				 {
				    if(cod[c1+4]==0)
				       cod[c1+4]=cod[c1+4]+49;
				    else
				       cod[c1+4]=cod[c1+4]+1;
				 }
			      }

			      strcpy(libro[cont].codigo,cod);
			      fondo(19,5,21,40,' ');
			      gotoxy(5,20);cout<<"Nuevo codigo de libro: ";
			      gotoxy(29,20);cout<<libro[cont].codigo;
			      gotoxy(5,22);
			      cout<<"Presione una tecla para continuar...";
			      getch();fondo(0,0,25,81,' ');
			    }

			  }
			while(k==0 && cod[0]!='0');
		     }
		     else
			{ seg='s';
			  clrscr();
			}
		  }
		  while(seg!='s'&&seg!='S');
		  break;
		case 4:
		  do
		  {
		     manten('l');
		     for(x=0; x<tam; x++)
		     {
			gotoxy(2,x+5); cout<<libro[x].codigo;
			gotoxy(10,x+5);cout<<libro[x].titulo;
			gotoxy(34,x+5);cout<<libro[x].autor;
			gotoxy(56,x+5);cout<<libro[x].stock;
			gotoxy(64,x+5);cout<<libro[x].precio;
			gotoxy(73,x+5);cout<<libro[x].estado;
		     }
		     gotoxy(3,x+15);cout<<"Volver al menu [S/N]: ";
		     gotoxy(25,x+15);
		     cin>>seg;
		     fondo(2,1,25,81,' ');
		  }
		  while(seg!='s'&&seg!='S');
		  break;
		case 0:
		  break;
	      }
	   }
	   while(opc1!=0);
	   break;

	 case 2:
	   do
	   {
	      fondo(24,19,23,60,' ');
	      m_ventas();
	      gotoxy(40,16);cout<<" CODIGO 0 SALIR ";
	      for(k=0; k<8; k++)
		  cod[k]='\x0';
	      k=0;
	      gotoxy(46,7);gets(cod);
	      if(cod[0]!='0')
	      {
		 do{  for(x=0; x<tam; x++)
			if(strcmpi(cod,libro[x].codigo)==0)
			{
			  k++;
			  vez=x;
			}

		      if(k==0)
		      {
			 gotoxy(25,20);
			 cout<<"Codigo Invalido, intentelo de nuevo";
			 getch();
			 fondo(20,25,21,60,' ');
			 fondo(7,46,8,55,' ');
			 gotoxy(46,7);gets(cod);
			 if(cod[0]=='0')
			   seg='s';
		      }
		      else
			 if(libro[vez].estado=='B')
			 {
			    gotoxy(25,20);
			    cout<<"El Libro no esta disponible para su venta";
			    fondo(20,25,21,70,' ');
			 }
		   }
		 while(k==0&&cod[0]!='0');
		 if(cod[0]!='0')
		 {
		   gotoxy(46,8); cin>>venta;
		   do
		   {
		      gotoxy(46,9); cin>>d;
		      gotoxy(49,9); cin>>m;
		      gotoxy(52,9); cin>>a;

		      if(d!=(int)f.da_day||m!=(int)f.da_mon||a!=(int)f.da_year)
		      {
			 gotoxy(29,22);
			 cout<<"La fecha no es valida";
			 getch();
			 fondo(21,27,24,50,' ');
		      }

		   }
		   while(d!=(int)f.da_day||m!=(int)f.da_mon||a!=(int)f.da_year);

		   gotoxy(30,12);cout<<"Confirmar [S/N]: ";
		   gotoxy(48,12);cin>>seg;

		   if(seg=='s'||seg=='S')
		   {
		      libro[vez].stock=libro[vez].stock-venta;
		      gotoxy(30,14);
		      cout<<"Venta confirmada";
		      getch();
		   }

		 }
	      }
	      else
		 { seg='s';
		   clrscr();
		 }

	   }
	   while(seg!='s'&&seg!='S');
	   break;


	 case 3:
	   do
	   {  m_busqueda();
	      cin>>opc1;
	      error(opc1,3);

	      for(x=0; x<tam-1; x++)
		 for(w=1; w<tam; w++)

		   if(strcmpi(libro[x].titulo, libro[w].titulo)<0)
		   {
		      aux=libro[x];
		      libro[x]=libro[w];
		      libro[w]=aux;
		   }

	      switch(opc1)
	      {
		 case 1:
		 {
		  do{
		      p_bustitulo();
		      gotoxy(62,15);cout<<" 0 PARA SALIR ";
		      for(k=0; k<30; k++)
			  titulo[k]='\x0';
		      gotoxy(11,6);
		      gets(titulo);
		      if(titulo[0]!='0')
		      {
			 k=0;
			 vez=0;
			 for(x=0; x<tam; x++)

			    if(strcmpi(libro[x].titulo, titulo)==0)
			    {
			       k++;
			       vez=x;
			    }

			 if(k==0)
			 {  gotoxy(30,18);
			    recuadro(17,28,19,59);
			    gotoxy(30,18);
			    cout<<"El libro que busca no existe";
			    getch();
			    fondo(17,25,20,60,' ');
			 }
			 else
			 {
			    gotoxy(3,8);
			    cout<<"Codigo  Autor                   Categoria             Precio  Stock  Estado";
			    gotoxy(3,10);cout<<libro[vez].codigo;
			    gotoxy(11,10);cout<<libro[vez].autor;
			    gotoxy(35,10);cout<<libro[vez].cat;
			    gotoxy(57,10);cout<<libro[vez].precio;
			    gotoxy(65,10);cout<<libro[vez].stock;
			    gotoxy(72,10);cout<<libro[vez].estado;
			    getch();
			    fondo(2,0,25,80,' ');
			 }
			 gotoxy(3,12);
			 cout<<"Desea realizar una nueva Busqueda[S/N]: ";
			 gotoxy(43,12);cin>>seg;
			 clrscr();
		      }
		      else
			 { seg='n';
			   clrscr();
			 }

		    }
		    while(seg=='s' || seg=='S');

		 }
		 break;

		 case 2:
		 {
		   do{ p_busqueda('c');
		       gotoxy(62,24);cout<<" 0 PARA SALIR ";
		       for(k=0; k<15; k++)
			  cat[k]='\x0';

		       gotoxy(14,6);
		       gets(cat);
		       if(cat[0]!='0')
		       {
			  k=0;

			  for(x=0; x<tam; x++)

			    if(strcmpi(libro[x].cat, cat)==0)
			    {
			       k++;
			       gotoxy(3,k+9);cout<<libro[x].codigo;
			       gotoxy(11,k+9);cout<<libro[x].titulo;
			       gotoxy(37,k+9);cout<<libro[x].autor;
			       gotoxy(58,k+9);cout<<libro[x].precio;
			       gotoxy(66,k+9);cout<<libro[x].stock;
			       gotoxy(73,k+9);cout<<libro[x].estado;

			    }

			  if(k==0)
			  {
			     gotoxy(30,18);
			     recuadro(17,28,19,53);
			     gotoxy(30,18);
			     cout<<"La categoria no existe";
			     getch();
			     fondo(17,28,20,59,' ');
			  }
			  else
			  {
			    gotoxy(3,8);
			    cout<<"Codigo  Titulo                    Autor                Precio  Stock  Estado";
			    getch();
			    fondo(2,0,25,81,' ');

			  }
			  gotoxy(3,23);cout<<"Desea realizar una nueva Busqueda[S/N]: ";
			  gotoxy(43,23);cin>>seg;
			  fondo(2,1,25,81,' ');
		       }
		       else
			  { seg='n';
			    clrscr();
			  }

		     }
		   while(seg=='s' || seg=='S');

		 }
		 break;

		 case 3:
		 {
		   do{  p_busqueda('a');
			gotoxy(62,24);cout<<" 0 PARA SALIR ";
			for(k=0; k<20; k++)
			  autor[k]='\x0';

			gotoxy(10,6);
			gets(autor);
			if(autor[0]!='0')
			{
			   k=0;

			   for(x=0; x<tam; x++)

			     if(strcmpi(libro[x].autor, autor)==0)
			     {
			       k++;
			       gotoxy(3,k+9);cout<<libro[x].codigo;
			       gotoxy(11,k+9);cout<<libro[x].titulo;
			       gotoxy(40,k+9);cout<<libro[x].cat;
			       gotoxy(58,k+9);cout<<libro[x].precio;
			       gotoxy(66,k+9);cout<<libro[x].stock;
			       gotoxy(73,k+9);cout<<libro[x].estado;

			     }

			   if(k==0)
			   {
			      gotoxy(30,18);
			      recuadro(17,28,19,49);
			      gotoxy(30,18);
			      cout<<"El Autor no existe";
			      getch();
			      fondo(17,28,20,59,' ');
			   }
			   else
			   {
			      gotoxy(3,8);
			      cout<<"Codigo  Titulo                       Categoria         Precio  Stock  Estado";
			      getch();
			      fondo(2,0,25,80,' ');

			   }

			   gotoxy(3,23);cout<<"Desea realizar una nueva Busqueda[S/N]: ";
			   gotoxy(43,23);cin>>seg;
			   fondo(2,1,24,81,' ');
			}
			else
			   { seg='n';
			     clrscr();
			   }

		     }
		   while(seg=='s' || seg=='S');
		 }
		 break;

	     }

	   }
	   while(opc1!=0);
	   break;

	 case 4:
	   do
	   {
	      m_consultas();
	      cin>>opc1;
	      error(opc1,2);
	   }
	   while(opc1!=0); break;
       }
       if(opc0!=0)
	  m_principal();
    }
    getch();

}

void recuadro(int arriba, int izq, int abajo, int der)
{

   int i=0;

   gotoxy(izq,arriba);cout<<"É";
   for(i=izq+1; i<der; i++)
       cout<<"Í";
   gotoxy(der,arriba);cout<<"»";
   for(i=arriba+1; i<abajo; i++)
   {
       gotoxy(izq,i);
       cout<<"º";
   }
   gotoxy(der,abajo);cout<<"¼";
   for(i=izq+1; i<der; i++)
   {
       gotoxy(i,abajo);
       cout<<"Í";
   }
   gotoxy(izq,abajo);cout<<"È";
   for(i=arriba+1; i<abajo; i++)
   {
       gotoxy(der,i);
       cout<<"º";
   }

}

void fondo(int arriba, int izq, int abajo, int der, char f)
{
   int i=0, k=0;
   for(i=izq; i<der; i++)
      for(k=arriba; k<abajo; k++)
      {
       gotoxy(i, k);
       cout<<f;
      }
}

void m_principal()
{
   clrscr();
   fondo(4,27,13,57,'Û');
   fondo(2,25,11,54,' ');
   recuadro(2,25,11,54);
   gotoxy(28,1);cout<<"***PROGRAMA LIBRERIA***";
   gotoxy(26,3);cout<<" 1. Mantenimiento de libros ";
   gotoxy(26,4);cout<<" 2. Venta de libros         ";
   gotoxy(26,5);cout<<" 3. Busqueda de un libro    ";
   gotoxy(26,6);cout<<" 4. Consulta de ventas      ";
   gotoxy(26,7);cout<<" 0. Salir                   ";
   gotoxy(27,9);cout<<"Seleccione opcion: ";
   gotoxy(46,9);
}

void m_manten()
{
    gotoxy(28,1);cout<<"***PROGRAMA LIBRERIA***";
    fondo(6,29,17,58,'Û');
    fondo(4,27,15,55,' ');
    recuadro(4,27,15,55);
    gotoxy(28,5) ; cout<<"  MANTENIMIENTO DE LIBROS  ";
    gotoxy(33,7) ; cout<<" 1. Alta      ";
    gotoxy(33,8) ; cout<<" 2. Baja      ";
    gotoxy(33,9) ; cout<<" 3. Modificar ";
    gotoxy(33,10); cout<<" 4. Listar    ";
    gotoxy(33,11); cout<<" 0. Volver    ";
    gotoxy(32,13); cout<<"Seleccione opcion: ";
    gotoxy(51,13);
}

void m_ventas()
{
    gotoxy(28,1);cout<<"***PROGRAMA LIBRERIA***";
    fondo(6,29,18,60,'Û');
    fondo(4,27,16,57,' ');
    recuadro(4,27,16,57);
    gotoxy(30,5); cout<<"  VENTA DE LIBROS  ";
    gotoxy(30,7); cout<<"Codigo________: ";
    gotoxy(30,8); cout<<"Cantidad______: ";
    gotoxy(30,9); cout<<"Fecha de venta:   /  /";
}

void m_busqueda()
{
    gotoxy(28,1);cout<<"***PROGRAMA LIBRERIA***";
    fondo(6,29,16,58,'Û');
    fondo(4,27,14,55,' ');
    recuadro(4,27,14,55);
    gotoxy(29,5);  cout<<"   Busqueda de un libro";
    gotoxy(29,7);  cout<<"1. Por titulo";
    gotoxy(29,8);  cout<<"2. Por categoria";
    gotoxy(29,9);  cout<<"3. Por autor";
    gotoxy(29,10); cout<<"0. Volver";
    gotoxy(29,12); cout<<"Seleccione opcion: ";
    gotoxy(48,12);
}

void m_consultas()
{
    gotoxy(28,1);cout<<"***PROGRAMA LIBRERIA***";
    fondo(6,29,15,58,'Û');
    fondo(4,27,13,55,' ');
    recuadro(4,27,13,55);
    gotoxy(30,5);  cout<<"Consulta de ventas";
    gotoxy(30,7);  cout<<"1. Por mes";
    gotoxy(30,8);  cout<<"2. Por periodo";
    gotoxy(30,9);  cout<<"0. Volver ";
    gotoxy(30,11); cout<<"Seleccione opcion: ";
    gotoxy(49,11);
}

void m_altas()
{
  clrscr();
  gotoxy(28,1);cout<<"***PROGRAMA LIBRERIA***";
  fondo(4,21,14,66,'Û');
  fondo(2,18,12,63,' ');
  recuadro(2,18,12,63);
  gotoxy(25,2);  cout<<" MANTENIMIENTO DE LIBROS-Altas ";
  gotoxy(20,4);  cout<<"1. Agregar nuevo libro                  ";
  gotoxy(20,5);  cout<<"2. Agregar ejemplares de libro existente";
  gotoxy(20,6);  cout<<"0. Volver";
  gotoxy(20,10); cout<<"Seleccione opcion: ";
  gotoxy(39,10);

}
void p_altcant()
{
   fondo(6,23,23,68,'Û');
   fondo(4,20,21,65,' ');
   recuadro(4,20,21,65);
   gotoxy(25,6);cout<<"Codigo: ";
   gotoxy(25,8);cout<<"Cantidad: ";

}

void p_bustitulo()
{
   fondo(4,1,15,80,' ');
   recuadro(4,1,15,80);
   gotoxy(30,4);cout<<" BUSQUEDA POR TITULO ";
   gotoxy(3,6);cout<<"Titulo: ";

}

void p_busqueda(char x)
{
   fondo(4,1,24,80,' ');
   recuadro(4,1,24,80);

   if(x=='a')
   {
      gotoxy(31,4);cout<<" BUSQUEDA POR AUTOR ";
      gotoxy(3,6);
      cout<<"Autor: ";
   }
   else
   {
      gotoxy(29,4);cout<<" BUSQUEDA POR CATEGORIA ";
      gotoxy(3,6);
      cout<<"Categoria: ";
   }

}
void error(int seleccion, int opciones)    // Devuelve mensaje de error
{                                          // si es una opcion que no esta
    if(seleccion>opciones)                 // en cualquiera de los menu
    {
       recuadro(19,18,21,62);
       gotoxy(19,20);
       cout<<"Opcion incorrecta, ENTER para continuar...";
       getch();
       fondo(18,18,22,63,' ');
       gotoxy(46,9);
    }
}


void manten(char c)
{
    gotoxy(28,1);
    cout<<"***PROGRAMA LIBRERIA***";
    fondo(1,2,24,80,' ');
    recuadro(2,1,24,80);
    switch(c)
    {
	case 'a': gotoxy(25,2);cout<<" MANTENIMIENTO DE LIBROS-Altas "; break;
	case 'b': gotoxy(25,2);cout<<" MANTENIMIENTO DE LIBROS-Bajas "; break;
	case 'm': gotoxy(22,2);cout<<" MANTENIMIENTO DE LIBROS-Modificacion "; break;
	case 'l': gotoxy(25,2);cout<<" MANTENIMIENTO DE LIBROS-Listado "; break;
    }
    if(c=='l')
    {   gotoxy(2,3);
	cout<<"Codigo  Titulo                  Autor                Stock   Precio  Estado";
    }
    else
    {	 gotoxy(5,4);cout<<"Titulo___: ";
	 gotoxy(5,6);cout<<"Autor____: ";
	 gotoxy(5,8);cout<<"Categoria: ";
	 gotoxy(5,10);cout<<"Precio___: ";
	 if(c=='m')
	 {
	    gotoxy(5,12);
	    cout<<"Estado___: ";
	 }
	 else
	   {  gotoxy(5,12);
	      cout<<"Cantidad_: ";
	   }
    }
}
