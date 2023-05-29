#ifndef MULTILISTA_H
#define MULTILISTA_H

using namespace std;

//Estructura para el manejo de la Multilista
struct estudiante {
	string nombre, carrera, actividad;
	int edad;
	int sigNom, sigCarr, sigAct, sigEdad; //variables de posicion en los datos
};

//Creaci?n de la clase Multilista
class Multilista{
	private:
		//Atributos de la Multilista 
		int *cabeceras;
		estudiante *datos;
		int tam;
		
	public:
		//Metodo Constructor (inicializacion de los atributos de la Multilista)
		Multilista(){
			cabeceras=new int[10];
			datos=new estudiante[10];
			tam=0;
			
			for(int i=0; i<10; i++)//inicializacion cabecera
				cabeceras[i]=-1;
				
			for(int i=0; i<10; i++){//inicializacion arreglo de datos
				datos[i].nombre="";
				datos[i].carrera="";
				datos[i].actividad="";
				datos[i].edad=NULL;
				datos[i].sigAct=-1;
				datos[i].sigCarr=-1;
				datos[i].sigEdad=-1;
				datos[i].sigNom=-1;
			}
				
		}
		
		//Destructor
		~Multilista(){
			delete[] datos;
			delete[] cabeceras;
		}
		
		//Metodos (acciones) de la Multilista
		bool insertar(string nom, string act, string carr, int edad);
		bool eliminar(int pos);
		bool multilistaLLena();
		bool multilistaVacia();
	    bool buscarNombre(string nom);
	    void obtenerMultilista();
		void obtenerNombres();
		void obtenerEdades();
		void obtenerCarreras(string carr);
		void obtenerActividades(string act);
};

bool Multilista :: multilistaVacia(){
	return tam==0;
}

bool Multilista :: multilistaLLena(){
	return tam==10;
}

bool Multilista :: insertar(string nom, string act, string carr, int edad){
	if(multilistaLLena()) return false;
	
	estudiante e;
	
	e.nombre=nom;
	e.carrera=carr;
	e.actividad=act;
	e.edad=edad;
	e.sigNom=-1;
	e.sigCarr=-1;
	e.sigAct=-1;
	e.sigEdad=-1;
	
	int k;
	
	/*Proceso para identificar la posicion de guardado del estudiante*/
	int i=0;
	while(datos[i].edad!=NULL){
		i++;
	}
	
	/*Validacion Nombre*/
	if(cabeceras[0]==-1){ //cabecera de nombre vacia
		cabeceras[0]=i;
	}else{
		k=cabeceras[0]; //posicion del primer nombre ordenado alfabeticamente
		
		if(nom<datos[k].nombre){ //caso en que el estudiante agregado sea menor alfabeticamente
			e.sigNom=cabeceras[0];
			cabeceras[0]=i;
		}
		else{
			while(true){
				if(datos[k].sigNom==-1) break;
				if(nom<datos[datos[k].sigNom].nombre) break;
				k=datos[k].sigNom;
			}
			e.sigNom=datos[k].sigNom;
			datos[k].sigNom=i;
		}
	}
	
	/*Validacion Carrera*/
	switch(carr[0]){
		//sistemas
		case 's': case 'S':
			k=cabeceras[1];
			if(cabeceras[1]==-1){ //cabecera de sistemas vacia
				cabeceras[1]=i;
			}
			else{
				while(true){
					if(datos[k].sigCarr==-1) break;
					k=datos[k].sigCarr;
				}
				e.sigCarr=-1;
				datos[k].sigCarr=i;
			}
			break;
		//industrial
		case 'i': case 'I':
			k=cabeceras[2];
			if(cabeceras[2]==-1){ //cabecera de industrial vacia
				cabeceras[2]=i;
			}
			else{
				while(true){
					if(datos[k].sigCarr==-1) break;
					k=datos[k].sigCarr;
				}
				e.sigCarr=-1;
				datos[k].sigCarr=i;
			}
			break;
		//electrica
		case 'e': case 'E':
			k=cabeceras[3];
			if(cabeceras[3]==-1){ //cabecera de electrica vacia
				cabeceras[3]=i;
			}
			else{
				while(true){
					if(datos[k].sigCarr==-1) break;
					k=datos[k].sigCarr;
				}
				e.sigCarr=-1;
				datos[k].sigCarr=i;
			}
			break;
		//catastral
		case 'c': case 'C':
			k=cabeceras[4];
			if(cabeceras[4]==-1){ //cabecera de catastral vacia
				cabeceras[4]=i;
			}
			else{
				while(true){
					if(datos[k].sigCarr==-1) break;
					k=datos[k].sigCarr;
				}
				e.sigCarr=-1;
				datos[k].sigCarr=i;
			}
			break;
	}
	
	/*Validacion Actividad*/
	switch(act[0]){
		//danza
		case 'd': case 'D':
			e.sigAct=cabeceras[5];
			cabeceras[5]=i;
			break;
		//beisbol y basquet
		case 'b': case 'B':
			if(act[1]=='a'){
				e.sigAct=cabeceras[6];
				cabeceras[6]=i;
			}
			if(act[1]=='e'){
				e.sigAct=cabeceras[8];
				cabeceras[8]=i;
			}
			break;
		//natacion
		case 'n': case 'N':
			e.sigAct=cabeceras[7];
			cabeceras[7]=i;
			break;
	}
	
	/*Validacion edad*/
	if(cabeceras[9]==-1){ //cabecera de edad vacia
		cabeceras[9]=i;
	}else{
		k=cabeceras[9]; //posicion de la mayor edad
		
		if(edad>datos[k].edad){ //caso en que la edad sea la mayor
			e.sigEdad=cabeceras[9];
			cabeceras[9]=i;
		}
		else{
			while(true){
				if(datos[k].sigEdad==-1) break;
				if(edad>datos[datos[k].sigEdad].edad) break;
				k=datos[k].sigEdad;
			}
			e.sigEdad=datos[k].sigEdad;
			datos[k].sigEdad=i;
		}
	}
	
	datos[i]=e;
	tam++;
	return true;
	
}



bool Multilista :: eliminar(int pos){
	if(multilistaVacia()) return false;
  
	if(datos[pos].edad!=NULL){
  	int k;
  	
  	/*Validacion Nombre*/
  	k=cabeceras[0];
  	if(cabeceras[0]==pos){ //posicion a eliminar en la cabecera
  		cabeceras[0]=datos[pos].sigNom;
  	}
  	else{
  		while(true){
  			if(datos[k].sigNom==pos) break;
  			k=datos[k].sigNom;
  		}
  		datos[k].sigNom=datos[pos].sigNom;
  	}
  	
  	
  	/*Validacion Carrera*/
    switch((datos[pos].carrera)[0]){
    	//sistemas
  		case 's': case 'S':
  			k=cabeceras[1];
	      	if(k!=-1){
	      		if(cabeceras[1]==pos){ //posicion a eliminar en la cabecera
	      			cabeceras[1]=datos[pos].sigCarr;
	      		}
	      		else{
	      			while(true){
	      				if(datos[k].sigCarr==pos) break;
	      				k=datos[k].sigCarr;
	      			}
	      			datos[k].sigCarr=datos[pos].sigCarr;
	      		}
	      	}
  			break;
  		//industrial
  		case 'i': case 'I':
	      	k=cabeceras[2];
	      	if(k!=-1){
	      		if(cabeceras[2]==pos){ //posicion a eliminar en la cabecera
	      			cabeceras[2]=datos[pos].sigCarr;
	      		}
	      		else{
	      			while(true){
	      				if(datos[k].sigCarr==pos) break;
	      				k=datos[k].sigCarr;
	      			}
	      			datos[k].sigCarr=datos[pos].sigCarr;
	      		}
	      	}
  			break;
  		//electrica
  		case 'e': case 'E':	
	      	k=cabeceras[3];
	      	if(k!=-1){
	      		if(cabeceras[3]==pos){ //posicion a eliminar en la cabecera
	      			cabeceras[3]=datos[pos].sigCarr;
	      		}
	      		else{
	      			while(true){
	      				if(datos[k].sigCarr==pos) break;
	      				k=datos[k].sigCarr;
	      			}
	      			datos[k].sigCarr=datos[pos].sigCarr;
	      		}
	      	}
  			break;
  		//catastral
  		case 'c': case 'C':
	      	k=cabeceras[4];
	      	if(k!=-1){
	      		if(cabeceras[4]==pos){ //posicion a eliminar en la cabecera
	      			cabeceras[4]=datos[pos].sigCarr;
	      		}
	      		else{
	      			while(true){
	      				if(datos[k].sigCarr==pos) break;
	      				k=datos[k].sigCarr;
	      			}
	      			datos[k].sigCarr=datos[pos].sigCarr;
	      		}
	      	}
  			break;
  	}
  	
  	/*Validacion Actividad*/
    switch((datos[pos].carrera)[0]){
    	//danza
      	case 'd': case 'D':
	  		k=cabeceras[5];
	      	if(k!=-1){
	      		if(cabeceras[5]==pos){ //posicion a eliminar en la cabecera
	      			cabeceras[5]=datos[pos].sigAct;
	      		}
	      		else{
	      			while(true){
	      				if(datos[k].sigAct==pos) break;
	      				k=datos[k].sigAct;
	      			}
	      			datos[k].sigAct=datos[pos].sigAct;
	      		}
	      	}
  			break;
  		//basquet y beisbol
  		case 'b': case 'B':
  			if((datos[pos].carrera)[1]=='a'){
	  			k=cabeceras[6];
	          	if(k!=-1){
	          		if(cabeceras[6]==pos){ //posicion a eliminar en la cabecera
	          			cabeceras[6]=datos[pos].sigAct;
	          		}
	          		else{
	          			while(true){
	          				if(datos[k].sigAct==pos) break;
	          				k=datos[k].sigAct;
	          			}
	          			datos[k].sigAct=datos[pos].sigAct;
	          		}
	          	}
  			}
  			if((datos[pos].carrera)[1]=='e'){
	        	k=cabeceras[8];
	        	if(k!=-1){
	        		if(cabeceras[8]==pos){ //posicion a eliminar en la cabecera
	        			cabeceras[8]=datos[pos].sigAct;
	        		}
	        		else{
	        			while(true){
	        				if(datos[k].sigAct==pos) break;
	        				k=datos[k].sigAct;
	        			}
	        			datos[k].sigAct=datos[pos].sigAct;
	        		}
	        	}
  			}
  			break;
  		//natacion
  		case 'n': case 'N':
  			k=cabeceras[7];
	      	if(k!=-1){
	      		if(cabeceras[7]==pos){ //posicion a eliminar en la cabecera
	      			cabeceras[7]=datos[pos].sigAct;
	      		}
	      		else{
	      			while(true){
	      				if(datos[k].sigAct==pos) break;
	      				k=datos[k].sigAct;
	      			}
	      			datos[k].sigAct=datos[pos].sigAct;
	      		}
	      	}
  			break;
    }
  	
  	/*Validacion Edad*/
  	k=cabeceras[9];
  	if(cabeceras[9]==pos){ //posicion a eliminar en la cabecera
  		cabeceras[9]=datos[pos].sigEdad;
  	}
  	else{
  		while(true){
  			if(datos[k].sigEdad==pos) break;
  			k=datos[k].sigEdad;
  		}
  		datos[k].sigEdad=datos[pos].sigEdad;
  	}
  
  
  	datos[pos].nombre="";
  	datos[pos].carrera="";
  	datos[pos].actividad="";
  	datos[pos].edad=NULL;
  	datos[pos].sigNom=-1;
  	datos[pos].sigCarr=-1;
  	datos[pos].sigAct=-1;
  	datos[pos].sigEdad=-1;
  	
  	tam--;
  	return true;
  }
  return false;
	
}

void Multilista :: obtenerNombres(){
	int k = cabeceras[0];
	
	cout<<"\nNOMBRE\tCARRERA\tACTIVIDAD\tEDAD"<<endl;
	
	if(!multilistaVacia()){
		while(true){
			cout<<datos[k].nombre<<"\t"<<datos[k].carrera<<"\t"<<datos[k].actividad<<"\t"<<datos[k].edad<<endl;
			if(datos[k].sigNom==-1) break;
			k=datos[k].sigNom;
		}
	}
	
}


void Multilista :: obtenerMultilista(){
	
	if(!multilistaVacia()){
    cout<<"\nPOS\tNOMBRE\tCARRERA\tACTIVIDAD\tEDAD"<<endl;
    for(int i=0;i<10;i++){
      if(datos[i].edad!=NULL){
        cout<<i<<"\t"<<datos[i].nombre<<"\t"<<datos[i].carrera<<"\t"<<datos[i].actividad<<"\t"<<datos[i].edad<<endl;
      }
    }
    cout<<endl;
	}
	
}

bool Multilista :: buscarNombre(string nom){
	
	if(!multilistaVacia()){
    
	    for(int i=0;i<10;i++){
	      if(datos[i].nombre==nom){
	        cout<<"\nPOS\tNOMBRE\tCARRERA\tACTIVIDAD\tEDAD"<<endl;
	        cout<<i<<"\t"<<datos[i].nombre<<"\t"<<datos[i].carrera<<"\t"<<datos[i].actividad<<"\t"<<datos[i].edad<<endl;
	        return true;
	      }
	    }
	    cout<<endl;
	}
  	return false;
	
}

void Multilista :: obtenerCarreras(string carr){
  int k=-1;
	switch(carr[0]){
    	case 's': case 'S':
			k=cabeceras[1];
			break;
		case 'i': case 'I':
			k=cabeceras[2];
			break;
		case 'e': case 'E':
			k=cabeceras[3];
			break;
		case 'c': case 'C':
			k=cabeceras[4];
			break;
  	}
	
	cout<<"\nNOMBRE\tCARRERA\tACTIVIDAD\tEDAD"<<endl;
	
	if(!multilistaVacia()){
		while(k!=-1){
			cout<<datos[k].nombre<<"\t"<<datos[k].carrera<<"\t"<<datos[k].actividad<<"\t"<<datos[k].edad<<endl;
			if(datos[k].sigCarr==-1) break;
			k=datos[k].sigCarr;
		}
	}
	
}

void Multilista :: obtenerActividades(string act){
  int k=-1;
	switch(act[0]){
    case 'd': case 'D':
			k=cabeceras[5];
      
			break;
		case 'b': case 'B':
      if(act[1]=='a')
			  k=cabeceras[6];
      if(act[1]=='e')
			  k=cabeceras[8];
			break;
		case 'n': case 'N':
			k=cabeceras[7];
			break;
  	}
	
	cout<<"\nNOMBRE\tCARRERA\tACTIVIDAD\tEDAD"<<endl;
	
	if(!multilistaVacia()){
		while(k!=-1){
			cout<<datos[k].nombre<<"\t"<<datos[k].carrera<<"\t"<<datos[k].actividad<<"\t"<<datos[k].edad<<endl;
			if(datos[k].sigAct==-1) break;
			k=datos[k].sigAct;
		}
	}
	
}

void Multilista :: obtenerEdades(){
	int k = cabeceras[9];
	
	cout<<"\nNOMBRE\tCARRERA\tACTIVIDAD\tEDAD"<<endl;
	
	if(!multilistaVacia()){
		while(k!=-1){
			cout<<datos[k].nombre<<"\t"<<datos[k].carrera<<"\t"<<datos[k].actividad<<"\t"<<datos[k].edad<<endl;
			if(datos[k].sigEdad==-1) break;
			k=datos[k].sigEdad;
		}
	}
	
}
#endif
