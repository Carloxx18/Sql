#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "bd_empresa.cpp"
#include "Per.cpp"


using namespace std;

class cliente : Per {
private: string nit;
public:
	cliente() {
	}
	cliente(string nom, string ape, string dir, int tel, string fn, string n) : Per(nom, ape, dir, tel, fn) {
		nit = n;
	}
	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setFecha_Nacimiento(int fn) { fecha_nacimiento = fn; }
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	string getFecha_Nacimiento() { return fecha_nacimiento; }
	
	void crear() {
		int q_estado;
		bd_empresa cn = bd_empresa();
		
		cn.abrir_conex();
		string t = to_string(telefono);
		if (cn.getConec()) {
		string  insertar = "INSERT INTO clientes(nit,nombre,apellido,direccion,telefono,fecha_naci VALUES ('" + nit + "','" + nombre + "','" + apellido + "','" + direccion + "',"+ t +",'" + fecha_naci + "')";
		const char* i = insertar.c_str();
	
		q_estado = mysql_query(cn.getConec(), i);
		if (!q_estado) {
			cout << "El ingreso fue exitoso" << endl;
		}
		else {
			cout << " Error al ingresar" << endl;
		}
		}
		else {
			cout << " Error el ingresar" << endl;
		}
		cn.cerrar_conex();
	}
	void leer() {
		int q_estado;
		bd_empresa cn = bd_empresa();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conex();
		
		if (cn.getConec()) {
			
			
			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConec(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConec());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5]<<"," << fila[6] <<endl;
				}
				
			}
			else {
				cout << " error la consulta" << endl;
			}

		}
		else {
			cout << " Error la conexion" << endl;
		}
		cn.cerrar_conex();
	}
};