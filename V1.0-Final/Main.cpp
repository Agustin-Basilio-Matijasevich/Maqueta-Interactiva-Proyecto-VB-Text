#include <windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <fstream>
using namespace std;

string username;
int Tuser = 0;
string tipo_usuario;
char comillas = '"';

void inicio_sesion();
void menu_admin();
void menu_escritor();
void menu_cliente();
void menu_empresa();
void menu_escritorpro();

int main()
{
	int Rmenu = 0;

	cout << "Bienvenido a la Maqueta interactiva del Proyecto VB Text\nEste sistema busca mostrar en un sistema informatico la experiencia de utilizar el sistema VB Text\ny mostrar su funcionamiento a grandes rasgos" << endl << endl;

iniciar:

	cout << "Por favor, seleccione una opcion y presione enter para continuar:" << endl << endl;
	cout << "Ingrese 1: Para iniciar sesion / Ingrese 2: Para registrarse / Ingrese 3: Para salir" << endl;
	cin >> Rmenu;
	cin.ignore();
	cout << "Se selecciono la opcion " << Rmenu << endl << endl;

	if (Rmenu == 1)
	{
		inicio_sesion();

		cout << endl;

		if (Tuser == 1)
		{
			tipo_usuario = "administrador";
			menu_admin();
		}
		else if (Tuser == 2)
		{
			tipo_usuario = "escritor";
			menu_escritor();
		}
		else if (Tuser == 3)
		{
			tipo_usuario = "cliente";
			menu_cliente();
		}
		else if (Tuser == 4)
		{
			tipo_usuario = "empresa";
			menu_empresa();
		}
		else if (Tuser == 5)
		{
			tipo_usuario = "escritor profesional";
			menu_escritorpro();
		}
		else
		{
			cout << "Fatal Error" << endl;
			exit(1);
		}
	}
	else if (Rmenu == 2)
	{
		int opcion = 0;

		cout << "Esto es una maqueta interactiva, por lo tanto el proceso de registro sera simulado, el mismo no afecta a la base de datos del programa ni permite incluir la informacion necesaria para el mismo" << endl << endl;

		cout << "¿Como que tipo de usuario quiere registrarse?" << endl << endl;

		cout << "Ingrese 1: Para seleccionar cliente estandar  /  Ingrese 2: Para seleccionar cliente empresa u organismo  /  Ingrese 3: Para seleccionar escritor amateur  /  Ingrese 4: Para seleccionar escritor profesional" << endl;

		cin >> opcion;

		if (opcion == 1)
		{
			cout << "A continuacion se pedira el CORREO ELECTRONICO, NUMERO DE DOCUMENTO que sera el usuario que se utilizara para iniciar sesion, CONTRASEÑA, y por ultimo NOMBRE DE USUARIO PUBLICO que sera el nombre que vera el resto de los usuarios cuando vean su perfil (Se recomendara utilizar el nombre y el apellido)" << endl << endl;
		}
		else if (opcion == 2)
		{
			cout << "A continuacion se pedira un CORREO ELECTRONICO para notificar al ente sobre sucesos relacionados con su cuenta, CUIT o CUIL de la empresa, NO SE QUE MAS PEDIR NACHO QUE IRIA? fijate con tu vieja" << endl << endl;
			cout << "Luego se analizara la informacion y dentro de las proximas 48hs se establecera comunicacion por correo electronico para finalizar el registro" << endl << endl;
		}
		else if (opcion == 3)
		{
			cout << "A continuacion se pedira el CORREO ELECTRONICO, NUMERO DE DOCUMENTO que sera el usuario que se utilizara para iniciar sesion, CONTRASEÑA, y por ultimo NOMBRE DE USUARIO PUBLICO que sera el nombre que vera el resto de los usuarios cuando vean su perfil (Se recomendara utilizar el nombre y el apellido)" << endl << endl;
		}
		else if (opcion == 4)
		{
			cout << "A continuacion se pedira el CORREO ELECTRONICO, NUMERO DE DOCUMENTO que sera el usuario que se utilizara para iniciar sesion, CONTRASEÑA, y por ultimo NOMBRE DE USUARIO PUBLICO que sera el nombre que vera el resto de los usuarios cuando vean su perfil (Se recomendara utilizar el nombre y el apellido), CERTIFICACION DE ESTUDIOS RELACIONADOS, escaneo en formato pdf de el o los titulos de estudio relacionados a la escritura o algun campo de la misma (un abogado puede ser bueno escribiendo contratos por ejemplo) que tenga el individuo, FOTO DEL DNI frontal y del reverso" << endl << endl;
			cout << "Luego se analizara la informacion y dentro de las proximas 48hs se establecera comunicacion por correo electronico para finalizar el registro" << endl << endl;
		}
		else
		{
			cout << "Fatal error" << endl << endl;
			goto Cerrado;
		}

		cout << "Registro completo" << endl << endl;
	}
	else if (Rmenu == 3)
	{
		goto Cerrado;
	}
	else
	{
		cout << "Esta opcion es invalida, Por favor intente nuevamente." << endl << endl;
		goto iniciar;
	}

Cerrado:
	cout << "Si quiere volver a realizar una operacion vuelva a abrir la maqueta" << endl << endl;
	cout << "A continuacion, la maqueta se cerrara" << endl << endl;
	system("pause");
	return 0;
}

void inicio_sesion()
{
	long long int usuario;
	string contrasena;

	//usuarios DNI/CUIL
	int admin = 0;
	int escritor = 43146475;
	int cliente = 42156789;
	long long int profesional = 20431464757;
	long long int empresa_cliente = 20421567897;

	//contraseñas
	string admin1 = "admin";
	string escritor1 = "escritor";
	string cliente1 = "cliente";
	string profesional1 = "profesional";
	string empresa_cliente1 = "poderjudicialchaco";

login:

	cout << "Ingrese su Usuario: (DNI/CUIL)" << endl;
	cin >> usuario;
	cin.ignore();

autentication:

	if (usuario == 0)
	{
		int control = 1;

		cout << "Ingrese la contrasena:" << endl;
		contrasena.clear();
		getline(cin, contrasena);

		control = admin1.compare(contrasena);

		if (control == 0)
		{
			cout << "Credenciales Validadas" << endl;
			Tuser = 1;
			username = "administrador";
		}
		else
		{
			cout << "Contrasena Invalida, Intente Nuevamente" << endl << endl;
			goto autentication;
		}
	}
	else if (usuario == 43146475)
	{
		int control = 1;

		cout << "Ingrese la contrasena:" << endl;
		contrasena.clear();
		getline(cin, contrasena);

		control = escritor1.compare(contrasena);

		if (control == 0)
		{
			cout << "Credenciales Validadas" << endl;
			Tuser = 2;
			username = "agustin";
		}
		else
		{
			cout << "Contrasena Invalida, Intente Nuevamente" << endl << endl;
			goto autentication;
		}
	}
	else if (usuario == 42156789)
	{
		int control = 1;

		cout << "Ingrese la contrasena:" << endl;
		contrasena.clear();
		getline(cin, contrasena);

		control = cliente1.compare(contrasena);

		if (control == 0)
		{
			cout << "Credenciales Validadas" << endl;
			Tuser = 3;
			username = "cliente";
		}
		else
		{
			cout << "Contrasena Invalida, Intente Nuevamente" << endl << endl;
			goto autentication;
		}
	}
	else if (usuario == 20431464757)
	{
		int control = 1;

		cout << "Ingrese la contrasena:" << endl;
		contrasena.clear();
		getline(cin, contrasena);

		control = profesional1.compare(contrasena);

		if (control == 0)
		{
			cout << "Credenciales Validadas" << endl;
			Tuser = 5;
			username = "Profesional de la escritura";
		}
		else
		{
			cout << "Contrasena Invalida, Intente Nuevamente" << endl << endl;
			goto autentication;
		}
	}
	else if (usuario == 20421567897)
	{
		int control = 1;

		cout << "Ingrese la contrasena:" << endl;
		contrasena.clear();
		getline(cin, contrasena);

		control = empresa_cliente1.compare(contrasena);

		if (control == 0)
		{
			cout << "Credenciales Validadas" << endl;
			Tuser = 4;
			username = "Poder Judicial del chaco";
		}
		else
		{
			cout << "Contrasena Invalida, Intente Nuevamente" << endl << endl;
			goto autentication;
		}
	}
	else
	{
		cout << "Usuario invalido, Por favor reintente" << endl << endl;
		goto login;
	}
}

void menu_admin()
{
	int opcion_menu = 0;

	cout << "Bienvenido " << username << ". Su tipo de usuario es: " << tipo_usuario << endl << endl;
	cout << "Por favor seleccione una de las siguientes opciones: " << endl << "Ingrese 1: Para revisar textos denunciados por copia.  Ingrese 2: Para salir" << endl;

	cin >> opcion_menu;

	if (opcion_menu == 1)
	{
		int existe_denuncia = 0;

		ifstream denuncia;

		denuncia.open(".\\Base de datos\\denuncia.txt", ios::in);

		if (denuncia.fail())
		{
			cout << "Fatal error" << endl;
			abort;
		}

		denuncia >> existe_denuncia;

		denuncia.close();

		if (existe_denuncia == 1)
		{
			ifstream nombre_trabajo;
			ifstream escritor_interesado;
			ifstream tipo_usuario_interesado;
			string titulo;
			string escritor;
			string tipo_usuario;

			nombre_trabajo.open(".\\Base de datos\\nombre_trabajo.txt", ios::in);
			escritor_interesado.open(".\\Base de datos\\escritor_interesado.txt", ios::in);
			tipo_usuario_interesado.open(".\\Base de datos\\tipo_usuario_interesado.txt", ios::in);

			getline(nombre_trabajo, titulo);
			getline(escritor_interesado, escritor);
			getline(tipo_usuario_interesado, tipo_usuario);

			nombre_trabajo.close();
			escritor_interesado.close();
			tipo_usuario_interesado.close();

			cout << "Existe una denuncia por copia para el texto titulado: " << titulo << endl << "Escrito por: " << escritor << ". Quien esta clasificado como: " << tipo_usuario << endl << endl << "A continuacion se muestra el texto denunciado:" << endl << endl;

			int sancion = 0;
			string texto_mostrar;
			ifstream texto;
			ofstream texto_salida;

			texto.open(".\\Base de datos\\texto.txt", ios::in);

			if (texto.fail())
			{
				cout << "Fatal error" << endl;
				abort;
			}

			while (!texto.eof())
			{
				getline(texto, texto_mostrar);
				cout << texto_mostrar << endl;
			}

			texto.close();

			cout << endl << "Por favor, seleccione una opcion: " << endl << "Ingrese 1: Para corroborar que el texto fue copiado, sancionar al escritor y eliminarlo  /  Ingrese 2: Para ignorar la denuncia" << endl;
			cin >> sancion;

			if (sancion == 1)
			{
				remove(".\\Base de datos\\texto.txt");
				texto_salida.open(".\\Base de datos\\texto.txt", ios::out);
				texto_salida << "Texto baneado por Copia ilegal";
				texto_salida.close();

				remove(".\\Base de datos\\denuncia.txt");
				texto_salida.open(".\\Base de datos\\denuncia.txt", ios::out);
				texto_salida << 0;
				texto_salida.close();

				cout << "El escritor fue sancionado y el texto eliminado" << endl << endl;
			}
			else if (sancion == 2)
			{
				remove(".\\Base de datos\\denuncia.txt");
				texto_salida.open(".\\Base de datos\\denuncia.txt", ios::out);
				texto_salida << 0;
				texto_salida.close();

				cout << "La denuncia fue ignorada" << endl;
			}
			else
			{
				cout << "Fatal error" << endl;
				abort;
			}
		}
		else if (existe_denuncia == 0)
		{
			cout << "No hay denuncias" << endl << endl;
		}
		else
		{
			cout << "Fatal Error" << endl;
			abort;
		}
	}
	else if (opcion_menu == 2)
	{
		abort;
	}
	else
	{
		cout << "Fatal error" << endl;
		exit(1);
	}
}

void menu_escritor()
{
	int opcion_menu = 0;

	cout << "Bienvenido " << username << ". Su tipo de usuario es: " << tipo_usuario << endl << endl;
	cout << "Por favor seleccione una de las siguientes opciones: " << endl << "Ingrese 1: Para ver las propuestas de trabajo activas  /  Ingrese 2: Para ver sus propuestas de trabajo que le hayan otorgado  \nIngrese 3: Para ver su valoracion como escritor  /  Ingrese 4: Para ver sus baneos por copia ilegal  /  Ingrese 5: Para salir" << endl;

	cin >> opcion_menu;

	if (opcion_menu == 1)
	{
		ifstream existe_propuesta;
		int propuesta1 = 0;

		existe_propuesta.open(".\\Base de datos\\existe_propuesta.txt", ios::in);

		existe_propuesta >> propuesta1;

		existe_propuesta.close();

		if (propuesta1 == 0)
		{
			cout << "No existen propuestas activas" << endl << endl;
		}
		else if (propuesta1 == 1)
		{
			ifstream autor_propuesta;
			ifstream detalles_propuesta;
			ifstream nombre_trabajo;
			string autor;
			string detalles;
			string titulo;
			int acepta = 0;

			autor_propuesta.open(".\\Base de datos\\autor_propuesta.txt", ios::in);
			detalles_propuesta.open(".\\Base de datos\\detalles_propuesta.txt", ios::in);
			nombre_trabajo.open(".\\Base de datos\\nombre_trabajo.txt", ios::in);

			getline(autor_propuesta, autor);
			getline(detalles_propuesta, detalles);
			getline(nombre_trabajo, titulo);

			autor_propuesta.close();
			detalles_propuesta.close();
			nombre_trabajo.close();

			cout << "Existe una propuesta de trabajo de " << autor << " Titulada " << comillas << titulo << comillas << endl << endl << "A continuacion se muestra la explicacion sobre el trabajo otorgada por el cliente" << endl << endl;
			cout << detalles << endl << endl;

			cout << "¿Desea solicitar el trabajo?" << endl << "Ingrese 1: Para ACEPTAR el trabajo  /  Ingrese 2: Para RECHAZAR el trabajo" << endl;
			cin >> acepta;
			cin.ignore();

			if (acepta == 1)
			{
				ofstream existe_propuestapro;
				ofstream existe_propuesta;
				ofstream existe_interesado;
				ofstream muestra;
				ofstream escritor_interesado;
				ofstream tipoU_interesado;
				string texto;

				remove(".\\Base de datos\\existe_propuestapro.txt");
				remove(".\\Base de datos\\existe_propuesta.txt");
				remove(".\\Base de datos\\existe_interesado.txt");
				remove(".\\Base de datos\\escritor_interesado.txt");
				existe_propuestapro.open(".\\Base de datos\\existe_propuestapro.txt", ios::out);
				existe_propuesta.open(".\\Base de datos\\existe_propuesta.txt", ios::out);
				existe_interesado.open(".\\Base de datos\\existe_interesado.txt", ios::out);
				escritor_interesado.open(".\\Base de datos\\escritor_interesado.txt", ios::out);
				tipoU_interesado.open(".\\Base de datos\\tipo_usuario_interesado.txt", ios::out);

				existe_propuestapro << 0;
				existe_propuesta << 0;
				existe_interesado << 1;
				escritor_interesado << username;
				tipoU_interesado << tipo_usuario;

				existe_propuestapro.close();
				existe_propuesta.close();
				existe_interesado.close();
				escritor_interesado.close();
				tipoU_interesado.close();

				cout << "Propuesta ACEPTADA" << endl << "Por favor, escriba una muestra de lo que tiene en mente para abordar la escritura de este texto" << endl << endl;

				getline(cin, texto);

				muestra.open(".\\Base de datos\\muestra.txt", ios::out);
				muestra << texto;
				muestra.close();

				cout << endl << "Muestra enviada, en caso de que el cliente le otorgue el trabajo le avisaremos, muchas gracias." << endl << endl;
			}
			else if (acepta == 2)
			{
				cout << "Propuesta RECHAZADA" << endl;
			}
			else
			{
				cout << "Fatal error" << endl;
				abort;
			}
		}
		else
		{
			cout << "Fatal error" << endl;
			abort;
		}
	}
	else if (opcion_menu == 2)
	{
		ifstream existe_propuestas_aceptadas;
		int propuestas_aceptadas;

		existe_propuestas_aceptadas.open(".\\Base de datos\\existe_propuestas_aceptadas.txt", ios::in);

		existe_propuestas_aceptadas >> propuestas_aceptadas;

		existe_propuestas_aceptadas.close();

		if (propuestas_aceptadas == 0)
		{
			cout << "No hay propuestas de trabajo que le hayan otorgado" << endl << endl;
		}
		else if (propuestas_aceptadas == 1)
		{
			ifstream nombre_trabajo;
			ifstream detalles_propuesta;
			string titulo;
			string detalles;
			int respuesta;

			nombre_trabajo.open(".\\Base de datos\\nombre_trabajo.txt", ios::in);
			detalles_propuesta.open(".\\Base de datos\\detalles_propuesta.txt", ios::in);

			getline(nombre_trabajo, titulo);
			getline(detalles_propuesta, detalles);

			nombre_trabajo.close();
			detalles_propuesta.close();

			cout << "Le otorgaron un trabajo para escribir un texto titulado: " << titulo << endl << endl;
			cout << "A continuacion se muestra la descripcion de lo que solicito el cliente que escriba" << endl << endl;
			cout << detalles << endl << endl;
			cout << "¿Quiere comenzar a escribir ahora?" << endl << "Ingrese 1: Para responer SI  /  Ingrese 2: Para responder NO" << endl;
			cin >> respuesta;
			cin.ignore();
			cout << endl;

			if (respuesta == 1)
			{
				ofstream texto;
				ofstream existe_propuestas_aceptadas;
				ofstream existe_texto_listo;
				string textocache;

				cout << "Por favor, a continuacion escriba el texto de su trabajo, recuerde que siendo esto una maqueta primitiva no puede usar el enter para bajar de renglon, si presiona enter se guardara lo que haya escrito y se cerrara el programa" << endl << endl;

				getline(cin, textocache);

				texto.open(".\\Base de datos\\texto.txt", ios::out);
				existe_propuestas_aceptadas.open(".\\Base de datos\\existe_propuestas_aceptadas.txt", ios::out);
				existe_texto_listo.open(".\\Base de datos\\existe_texto_listo.txt", ios::out);

				texto << textocache;
				existe_propuestas_aceptadas << 0;
				existe_texto_listo << 1;

				texto.close();
				existe_propuestas_aceptadas.close();
				existe_texto_listo.close();

				cout << endl << "Texto guardado con exito" << endl << endl;
			}
			else if (respuesta == 2)
			{
				abort;
			}
		}
	}
	else if (opcion_menu == 3)
	{
		cout << "Su valoracion como escritor es de 4/10 puntos\nRecuerde que si logra una puntuacion de 8/10 o mayor y con 500 textos escritos podra realizar un examen para ascender a la categoria de escritor profesional, este examen aparecera automaticamente como una opcion cuando cumpla los requisitos, tambien se le notificara de ello\nSus comentarios son los siguientes: " << endl << endl;
		cout << "Comentarios..." << endl << endl;
	}
	else if (opcion_menu == 4)
	{
		cout << "Usted tiene 2 baneos confirmados por copiar texto de forma ilegal\nRecuerde que al 3er baneo su cuenta sera eliminada y sus datos no se podran usar nuevamente para crear otro usuario\nCon 2 baneos usted ya no califica para rendir el examen de ascenso de categoria ni calificara nunca" << endl << endl;
	}
	else if (opcion_menu == 5)
	{
		abort;
	}
	else
	{
		cout << "Fatal error" << endl;
		abort;
	}
}

void menu_cliente()
{
	int opcion_menu = 0;

	cout << "Bienvenido " << username << ". Su tipo de usuario es: " << tipo_usuario << endl << endl;
	cout << "Por favor seleccione una de las siguientes opciones: " << endl << "Ingrese 1: Para crear propuesta de Trabajo (solo profesionales)  /  Ingrese 2: Para ver las propuestas con interesados  \nIngrese 3: Para ver trabajos terminados (textos listos)  /  Ingrese 4: Para salir" << endl;

	cin >> opcion_menu;
	cin.ignore();

	if (opcion_menu == 1)
	{
		ofstream detalles_propuesta;
		ofstream existe_propuestapro;
		ofstream existe_propuesta;
		ofstream autor_propuesta;
		ofstream nombre_trabajo;
		string Ntrabajo;
		string texto;

		cout << endl << "Por favor, a continuacion escriba un titulo para el texto que usted solicita, con este titulo usted y el escritor podran identificar el trabajo que esta creando." << endl << endl;

		getline(cin, Ntrabajo);

		cout << endl << "Por favor, a continuacion especifique los datos sobre el texto que necesita para que el escritor pueda guiarse a la hora de escribirlo." << endl << endl;

		getline(cin, texto);

		detalles_propuesta.open(".\\Base de datos\\detalles_propuesta.txt", ios::out);
		existe_propuestapro.open(".\\Base de datos\\existe_propuestapro.txt", ios::out);
		existe_propuesta.open(".\\Base de datos\\existe_propuesta.txt", ios::out);
		autor_propuesta.open(".\\Base de datos\\autor_propuesta.txt", ios::out);
		nombre_trabajo.open(".\\Base de datos\\nombre_trabajo.txt", ios::out);

		nombre_trabajo << Ntrabajo;
		detalles_propuesta << texto;

		existe_propuestapro << 0;
		existe_propuesta << 1;
		autor_propuesta << username;

		existe_propuestapro.close();
		detalles_propuesta.close();
		existe_propuesta.close();
		autor_propuesta.close();
		nombre_trabajo.close();

		cout << endl << "Propuesta de trabajo creada exitosamente" << endl << endl;
	}
	else if (opcion_menu == 2)
	{
		ifstream existe_interesado;
		int interesado;

		existe_interesado.open(".\\Base de datos\\existe_interesado.txt", ios::in);
		existe_interesado >> interesado;
		existe_interesado.close();

		if (interesado == 0)
		{
			cout << "No existen interesados en realizar un trabajo propuesto por usted" << endl << endl;
		}
		else if (interesado == 1)
		{
			ifstream nombre_trabajo;
			ifstream escritor_interesado;
			ifstream tipoU_interesado;
			ifstream muestra;
			string trabajo;
			string usuario;
			string tipousuario;
			string texto;
			int respuesta = 0;

			nombre_trabajo.open(".\\Base de datos\\nombre_trabajo.txt", ios::in);
			escritor_interesado.open(".\\Base de datos\\escritor_interesado.txt", ios::in);
			tipoU_interesado.open(".\\Base de datos\\tipo_usuario_interesado.txt", ios::in);
			muestra.open(".\\Base de datos\\muestra.txt", ios::in);

			getline(nombre_trabajo, trabajo);
			getline(escritor_interesado, usuario);
			getline(tipoU_interesado, tipousuario);
			getline(muestra, texto);

			nombre_trabajo.close();
			escritor_interesado.close();
			tipoU_interesado.close();
			muestra.close();

			cout << "Existe un escritor interesado en realizar el trabajo " << comillas << trabajo << comillas << endl;
			cout << "El nombre de usuario del escritor interesado es: " << usuario << endl;
			cout << "El tipo de usuario que posee es: " << tipousuario << endl << endl;

			cout << "A continuacion se muestra un texto a escrito por el escritor a modo de muestra sobre lo que tiene preparado para abordar el trabajo" << endl << endl;

			cout << texto << endl << endl;

			cout << "Desea otorgarle el trabajo a " << usuario << "?" << endl << endl;
			cout << "Ingrese 1: Para responder que si  /  Ingrese 2: Para responder que no" << endl;
			cin >> respuesta;

			if (respuesta == 1)
			{
				ofstream existe_interesado;
				ofstream existe_propuestas_aceptadas;

				remove(".\\Base de datos\\existe_interesado.txt");
				remove(".\\Base de datos\\existe_propuestas_aceptadas.txt");

				existe_interesado.open(".\\Base de datos\\existe_interesado.txt", ios::out);
				existe_propuestas_aceptadas.open(".\\Base de datos\\existe_propuestas_aceptadas.txt", ios::out);

				existe_interesado << 0;
				existe_propuestas_aceptadas << 1;

				existe_interesado.close();
				existe_propuestas_aceptadas.close();

				cout << "Se le otorgo con exito el trabajo a " << usuario << ". Le avisaremos cuando el trabajo este terminado" << endl << endl;
			}
			else if (respuesta == 2)
			{
				ofstream existe_interesadoout;

				existe_interesadoout.open(".\\Base de datos\\existe_interesado.txt", ios::out);

				existe_interesadoout << 0;

				existe_interesadoout.close();

				cout << "Usted rechazo otorgarle el trabajo a " << usuario << endl;
				cout << "No volvera a ver a este escritor como interesado en realizar su trabajo titulado " << comillas << trabajo << comillas << endl << endl;
			}
		}
		else
		{
			cout << "Fatal error" << endl;
			exit(1);
		}
	}
	else if (opcion_menu == 3)
	{
		ifstream existe_texto_listo;
		int control = 0;

		existe_texto_listo.open(".\\Base de datos\\existe_texto_listo.txt", ios::in);

		existe_texto_listo >> control;

		existe_texto_listo.close();

		if (control == 0)
		{
			cout << "No existen trabajos terminados" << endl << endl;
			abort;
		}
		else if (control == 1)
		{
			ifstream escritor_interesado;
			ifstream tipo_usuario_interesado;
			ifstream nombre_trabajo;
			ifstream detalles_propuesta;
			ifstream texto;
			string nombre_escritor;
			string tipo_escritor;
			string nombre_texto;
			string detalles_texto;
			string textocache;
			int menu = 0;

			escritor_interesado.open(".\\Base de datos\\escritor_interesado.txt", ios::in);
			tipo_usuario_interesado.open(".\\Base de datos\\tipo_usuario_interesado.txt", ios::in);
			nombre_trabajo.open(".\\Base de datos\\nombre_trabajo.txt", ios::in);
			detalles_propuesta.open(".\\Base de datos\\detalles_propuesta.txt", ios::in);

			getline(escritor_interesado, nombre_escritor);
			getline(tipo_usuario_interesado, tipo_escritor);
			getline(nombre_trabajo, nombre_texto);
			getline(detalles_propuesta, detalles_texto);

			escritor_interesado.close();
			tipo_usuario_interesado.close();
			nombre_trabajo.close();
			detalles_propuesta.close();

			cout << "Existe un texto titulado: " << comillas << nombre_texto << comillas << endl << "Escrito por: " << nombre_escritor << ". Quien esta clasificado como: " << tipo_escritor << endl << endl;
			cout << "A continuacion se muestran los detalles que usted le otorgo al escritor para que realize su texto: " << endl << endl;

			cout << detalles_texto << endl << endl;

			cout << "A continuacion se abre el texto escrito por el escritor: " << endl << endl;

			texto.open(".\\Base de datos\\texto.txt", ios::in);

			while (!texto.eof())
			{
				getline(texto, textocache);
				cout << textocache;
			}

			cout << endl << endl;

			texto.close();

			ifstream denuncia;
			int alerta;

			denuncia.open(".\\Base de datos\\denuncia.txt", ios::in);

			denuncia >> alerta;

			denuncia.close();

			if (alerta == 0)
			{
				cout << "Por favor seleccione alguna de las siguientes opciones: " << endl << "Ingrese 1: Para valorar de forma positiva el trabajo del escritor  /  Ingrese 2: Para valorar de forma negativa el trabajo del escritor\nIngrese 3: Para denunciar que el texto escrito fue copiado ilegalmente de otra fuente que no es el escritor" << endl;

				cin >> menu;

				if (menu == 1)
				{
					int descargar;

					cout << endl << "Se valoro al escritor de forma positiva, esto afectara en su calificacion como escritor" << endl << endl;

					cout << "¿Quiere descargar el texto ahora?" << endl << "Ingrese 1: Para responder si  /  Ingrese 2: Para responder no" << endl;

					cin >> descargar;

					if (descargar == 1)
					{
						ofstream descarga;
						stringstream formato;
						string con_formato;
						string auxilio;

						formato << ".\\Descargas\\" << nombre_texto << ".txt";
						con_formato = formato.str();

						texto.open(".\\Base de datos\\texto.txt", ios::in);
						descarga.open(con_formato.c_str(), ios::out);

						while (!texto.eof())
						{
							getline(texto, auxilio);
							descarga << auxilio;
						}

						texto.close();
						descarga.close();

						cout << "Texto descargado correctamente" << endl << endl;
					}
					else if (descargar == 2)
					{
						cout << endl << "No se descargara el archivo" << endl << endl;
					}
				}
				else if (menu == 2)
				{
					cout << endl << "Se valoro al escritor de forma negariva, esto afectara en su calificacion como escritor" << endl << endl;
				}
				else if (menu == 3)
				{
					ofstream denuncia;

					denuncia.open(".\\Base de datos\\denuncia.txt", ios::out);

					denuncia << 1;

					denuncia.close();

					cout << "La denuncia fue enviada con exito, retendremos el texto dentro de la plataforma hasta que la misma sea confirmada o rechazada, mientras tanto podra ver el texto en el sistema pero no copiarlo o descargarlo, en caso de que la denuncia sea aceptada o rechazada se le avisara y si fue rechazada se le permitira descargar el texto y para volver a denunciarlo tendra que dar explicaciones sobre el autor o sitio al que usted dice fue robado, Muchas gracias." << endl << endl;
				}
				else
				{
					cout << "Fatal error" << endl << endl;
					abort;
				}
			}
			else if (alerta == 1)
			{
				cout << "El texto fue denunciado por copia ilegal, no puede realizar acciones sobre el por ahora, cuando esta denuncia sea revisada le avisaremos" << endl << endl;
			}
			else
			{
				cout << "Fatal error" << endl << endl;
				abort;
			}
		}
		else
		{
			cout << "Fatal error" << endl;
			exit(1);
		}
	}
	else if (opcion_menu == 4)
	{
		abort;
	}
	else
	{
		cout << "Fatal error" << endl;
		abort;
	}
}
void menu_empresa()
{
	int opcion_menu = 0;

	cout << "Bienvenido " << username << ". Su tipo de usuario es: " << tipo_usuario << endl << endl;
	cout << "Por favor seleccione una de las siguientes opciones: " << endl << "Ingrese 1: Para crear propuesta de Trabajo (solo profesionales)  /  Ingrese 2: Para ver las propuestas con interesados  \nIngrese 3: Para ver trabajos terminados (textos listos)  /  Ingrese 4: Para salir" << endl;

	cin >> opcion_menu;
	cin.ignore();

	if (opcion_menu == 1)
	{
		ofstream detalles_propuesta;
		ofstream existe_propuestapro;
		ofstream existe_propuesta;
		ofstream autor_propuesta;
		ofstream nombre_trabajo;
		string Ntrabajo;
		string texto;

		cout << endl << "Por favor, a continuacion escriba un titulo para el texto que usted solicita, con este titulo usted y el escritor podran identificar el trabajo que esta creando." << endl << endl;

		getline(cin, Ntrabajo);

		cout << endl << "Por favor, a continuacion especifique los datos sobre el texto que necesita para que el escritor pueda guiarse a la hora de escribirlo." << endl << endl;

		getline(cin, texto);

		detalles_propuesta.open(".\\Base de datos\\detalles_propuesta.txt", ios::out);
		existe_propuestapro.open(".\\Base de datos\\existe_propuestapro.txt", ios::out);
		existe_propuesta.open(".\\Base de datos\\existe_propuesta.txt", ios::out);
		autor_propuesta.open(".\\Base de datos\\autor_propuesta.txt", ios::out);
		nombre_trabajo.open(".\\Base de datos\\nombre_trabajo.txt", ios::out);

		nombre_trabajo << Ntrabajo;
		detalles_propuesta << texto;

		existe_propuestapro << 1;
		existe_propuesta << 0;
		autor_propuesta << username;

		existe_propuestapro.close();
		detalles_propuesta.close();
		existe_propuesta.close();
		autor_propuesta.close();
		nombre_trabajo.close();

		cout << endl << "Propuesta de trabajo creada exitosamente" << endl << endl;
	}
	else if (opcion_menu == 2)
	{
		ifstream existe_interesado;
		int interesado;

		existe_interesado.open(".\\Base de datos\\existe_interesado.txt", ios::in);
		existe_interesado >> interesado;
		existe_interesado.close();

		if (interesado == 0)
		{
			cout << "No existen interesados en realizar un trabajo propuesto por usted" << endl << endl;
		}
		else if (interesado == 1)
		{
			ifstream nombre_trabajo;
			ifstream escritor_interesado;
			ifstream tipoU_interesado;
			ifstream muestra;
			string trabajo;
			string usuario;
			string tipousuario;
			string texto;
			int respuesta = 0;

			nombre_trabajo.open(".\\Base de datos\\nombre_trabajo.txt", ios::in);
			escritor_interesado.open(".\\Base de datos\\escritor_interesado.txt", ios::in);
			tipoU_interesado.open(".\\Base de datos\\tipo_usuario_interesado.txt", ios::in);
			muestra.open(".\\Base de datos\\muestra.txt", ios::in);

			getline(nombre_trabajo, trabajo);
			getline(escritor_interesado, usuario);
			getline(tipoU_interesado, tipousuario);
			getline(muestra, texto);

			nombre_trabajo.close();
			escritor_interesado.close();
			tipoU_interesado.close();
			muestra.close();

			cout << "Existe un escritor interesado en realizar el trabajo " << comillas << trabajo << comillas << endl;
			cout << "El nombre de usuario del escritor interesado es: " << usuario << endl;
			cout << "El tipo de usuario que posee es: " << tipousuario << endl << endl;

			cout << "A continuacion se muestra un texto a escrito por el escritor a modo de muestra sobre lo que tiene preparado para abordar el trabajo" << endl << endl;

			cout << texto << endl << endl;

			cout << "Desea otorgarle el trabajo a " << usuario << "?" << endl << endl;
			cout << "Ingrese 1: Para responder que si  /  Ingrese 2: Para responder que no" << endl;
			cin >> respuesta;

			if (respuesta == 1)
			{
				ofstream existe_interesado;
				ofstream existe_propuestas_aceptadas;

				remove(".\\Base de datos\\existe_interesado.txt");
				remove(".\\Base de datos\\existe_propuestas_aceptadas.txt");

				existe_interesado.open(".\\Base de datos\\existe_interesado.txt", ios::out);
				existe_propuestas_aceptadas.open(".\\Base de datos\\existe_propuestas_aceptadas.txt", ios::out);

				existe_interesado << 0;
				existe_propuestas_aceptadas << 1;

				existe_interesado.close();
				existe_propuestas_aceptadas.close();

				cout << "Se le otorgo con exito el trabajo a " << usuario << ". Le avisaremos cuando el trabajo este terminado" << endl << endl;
			}
			else if (respuesta == 2)
			{
				ofstream existe_interesadoout;

				existe_interesadoout.open(".\\Base de datos\\existe_interesado.txt", ios::out);

				existe_interesadoout << 0;

				existe_interesadoout.close();

				cout << "Usted rechazo otorgarle el trabajo a " << usuario << endl;
				cout << "No volvera a ver a este escritor como interesado en realizar su trabajo titulado " << comillas << trabajo << comillas << endl << endl;
			}
		}
		else
		{
			cout << "Fatal error" << endl;
			exit(1);
		}
	}
	else if (opcion_menu == 3)
	{
		ifstream existe_texto_listo;
		int control = 0;

		existe_texto_listo.open(".\\Base de datos\\existe_texto_listo.txt", ios::in);

		existe_texto_listo >> control;

		existe_texto_listo.close();

		if (control == 0)
		{
			cout << "No existen trabajos terminados" << endl << endl;
			abort;
		}
		else if (control == 1)
		{
			ifstream escritor_interesado;
			ifstream tipo_usuario_interesado;
			ifstream nombre_trabajo;
			ifstream detalles_propuesta;
			ifstream texto;
			string nombre_escritor;
			string tipo_escritor;
			string nombre_texto;
			string detalles_texto;
			string textocache;
			int menu = 0;

			escritor_interesado.open(".\\Base de datos\\escritor_interesado.txt", ios::in);
			tipo_usuario_interesado.open(".\\Base de datos\\tipo_usuario_interesado.txt", ios::in);
			nombre_trabajo.open(".\\Base de datos\\nombre_trabajo.txt", ios::in);
			detalles_propuesta.open(".\\Base de datos\\detalles_propuesta.txt", ios::in);

			getline(escritor_interesado, nombre_escritor);
			getline(tipo_usuario_interesado, tipo_escritor);
			getline(nombre_trabajo, nombre_texto);
			getline(detalles_propuesta, detalles_texto);

			escritor_interesado.close();
			tipo_usuario_interesado.close();
			nombre_trabajo.close();
			detalles_propuesta.close();

			cout << "Existe un texto titulado: " << comillas << nombre_texto << comillas << endl << "Escrito por: " << nombre_escritor << ". Quien esta clasificado como: " << tipo_escritor << endl << endl;
			cout << "A continuacion se muestran los detalles que usted le otorgo al escritor para que realize su texto: " << endl << endl;

			cout << detalles_texto << endl << endl;

			cout << "A continuacion se abre el texto escrito por el escritor: " << endl << endl;

			texto.open(".\\Base de datos\\texto.txt", ios::in);

			while (!texto.eof())
			{
				getline(texto, textocache);
				cout << textocache;
			}

			cout << endl << endl;

			texto.close();

			ifstream denuncia;
			int alerta;

			denuncia.open(".\\Base de datos\\denuncia.txt", ios::in);

			denuncia >> alerta;

			denuncia.close();

			if (alerta == 0)
			{
				cout << "Por favor seleccione alguna de las siguientes opciones: " << endl << "Ingrese 1: Para valorar de forma positiva el trabajo del escritor  /  Ingrese 2: Para valorar de forma negativa el trabajo del escritor\nIngrese 3: Para denunciar que el texto escrito fue copiado ilegalmente de otra fuente que no es el escritor" << endl;

				cin >> menu;

				if (menu == 1)
				{
					int descargar;

					cout << endl << "Se valoro al escritor de forma positiva, esto afectara en su calificacion como escritor" << endl << endl;

					cout << "¿Quiere descargar el texto ahora?" << endl << "Ingrese 1: Para responder si  /  Ingrese 2: Para responder no" << endl;

					cin >> descargar;

					if (descargar == 1)
					{
						ofstream descarga;
						stringstream formato;
						string con_formato;
						string auxilio;

						formato << ".\\Descargas\\" << nombre_texto << ".txt";
						con_formato = formato.str();

						texto.open(".\\Base de datos\\texto.txt", ios::in);
						descarga.open(con_formato.c_str(), ios::out);

						while (!texto.eof())
						{
							getline(texto, auxilio);
							descarga << auxilio;
						}

						texto.close();
						descarga.close();

						cout << "Texto descargado correctamente" << endl << endl;
					}
					else if (descargar == 2)
					{
						cout << endl << "No se descargara el archivo" << endl << endl;
					}
				}
				else if (menu == 2)
				{
					cout << endl << "Se valoro al escritor de forma negariva, esto afectara en su calificacion como escritor" << endl << endl;
				}
				else if (menu == 3)
				{
					ofstream denuncia;

					denuncia.open(".\\Base de datos\\denuncia.txt", ios::out);

					denuncia << 1;

					denuncia.close();

					cout << "La denuncia fue enviada con exito, retendremos el texto dentro de la plataforma hasta que la misma sea confirmada o rechazada, mientras tanto podra ver el texto en el sistema pero no copiarlo o descargarlo, en caso de que la denuncia sea aceptada o rechazada se le avisara y si fue rechazada se le permitira descargar el texto y para volver a denunciarlo tendra que dar explicaciones sobre el autor o sitio al que usted dice fue robado, Muchas gracias." << endl << endl;
				}
				else
				{
					cout << "Fatal error" << endl << endl;
					abort;
				}
			}
			else if (alerta == 1)
			{
				cout << "El texto fue denunciado por copia ilegal, no puede realizar acciones sobre el por ahora, cuando esta denuncia sea revisada le avisaremos" << endl << endl;
			}
			else
			{
				cout << "Fatal error" << endl << endl;
				abort;
			}
		}
		else
		{
			cout << "Fatal error" << endl;
			exit(1);
		}
	}
	else if (opcion_menu == 4)
	{
		abort;
	}
	else
	{
		cout << "Fatal error" << endl;
		abort;
	}
}
void menu_escritorpro()
{
	int opcion_menu = 0;

	cout << "Bienvenido " << username << ". Su tipo de usuario es: " << tipo_usuario << endl << endl;
	cout << "Por favor seleccione una de las siguientes opciones: " << endl << "Ingrese 1: Para ver las propuestas de trabajo activas  /  Ingrese 2: Para ver sus propuestas de trabajo que le hayan otorgado  \nIngrese 3: Para ver su valoracion como escritor  /  Ingrese 4: Para ver sus baneos por copia ilegal  /  Ingrese 5: Para salir" << endl;

	cin >> opcion_menu;

	if (opcion_menu == 1)
	{
		ifstream existe_propuestapro;
		ifstream existe_propuesta;
		int propuesta1 = 0;
		int propuesta2 = 0;

		existe_propuestapro.open(".\\Base de datos\\existe_propuestapro.txt", ios::in);
		existe_propuesta.open(".\\Base de datos\\existe_propuesta.txt", ios::in);

		existe_propuestapro >> propuesta1;
		existe_propuesta >> propuesta2;
		propuesta1 += propuesta2;

		existe_propuestapro.close();
		existe_propuesta.close();

		if (propuesta1 == 0)
		{
			cout << "No existen propuestas activas" << endl << endl;
		}
		else if (propuesta1 == 1)
		{
			ifstream autor_propuesta;
			ifstream detalles_propuesta;
			ifstream nombre_trabajo;
			string autor;
			string detalles;
			string titulo;
			int acepta = 0;

			autor_propuesta.open(".\\Base de datos\\autor_propuesta.txt", ios::in);
			detalles_propuesta.open(".\\Base de datos\\detalles_propuesta.txt", ios::in);
			nombre_trabajo.open(".\\Base de datos\\nombre_trabajo.txt", ios::in);

			getline(autor_propuesta, autor);
			getline(detalles_propuesta, detalles);
			getline(nombre_trabajo, titulo);

			autor_propuesta.close();
			detalles_propuesta.close();
			nombre_trabajo.close();

			cout << "Existe una propuesta de trabajo de " << autor << " Titulada " << comillas << titulo << comillas << endl << endl << "A continuacion se muestra la explicacion sobre el trabajo otorgada por el cliente" << endl << endl;
			cout << detalles << endl << endl;

			cout << "¿Desea solicitar el trabajo?" << endl << "Ingrese 1: Para ACEPTAR el trabajo  /  Ingrese 2: Para RECHAZAR el trabajo" << endl;
			cin >> acepta;
			cin.ignore();

			if (acepta == 1)
			{
				ofstream existe_propuestapro;
				ofstream existe_propuesta;
				ofstream existe_interesado;
				ofstream muestra;
				ofstream escritor_interesado;
				ofstream tipoU_interesado;
				string texto;

				remove(".\\Base de datos\\existe_propuestapro.txt");
				remove(".\\Base de datos\\existe_propuesta.txt");
				remove(".\\Base de datos\\existe_interesado.txt");
				remove(".\\Base de datos\\escritor_interesado.txt");
				existe_propuestapro.open(".\\Base de datos\\existe_propuestapro.txt", ios::out);
				existe_propuesta.open(".\\Base de datos\\existe_propuesta.txt", ios::out);
				existe_interesado.open(".\\Base de datos\\existe_interesado.txt", ios::out);
				escritor_interesado.open(".\\Base de datos\\escritor_interesado.txt", ios::out);
				tipoU_interesado.open(".\\Base de datos\\tipo_usuario_interesado.txt", ios::out);

				existe_propuestapro << 0;
				existe_propuesta << 0;
				existe_interesado << 1;
				escritor_interesado << username;
				tipoU_interesado << tipo_usuario;

				existe_propuestapro.close();
				existe_propuesta.close();
				existe_interesado.close();
				escritor_interesado.close();
				tipoU_interesado.close();

				cout << "Propuesta ACEPTADA" << endl << "Por favor, escriba una muestra de lo que tiene en mente para abordar la escritura de este texto" << endl << endl;

				getline(cin, texto);

				muestra.open(".\\Base de datos\\muestra.txt", ios::out);
				muestra << texto;
				muestra.close();

				cout << endl << "Muestra enviada, en caso de que el cliente le otorgue el trabajo le avisaremos, muchas gracias." << endl << endl;
			}
			else if (acepta == 2)
			{
				cout << "Propuesta RECHAZADA" << endl;
			}
			else
			{
				cout << "Fatal error" << endl;
				abort;
			}
		}
		else
		{
			cout << "Fatal error" << endl;
			abort;
		}
	}
	else if (opcion_menu == 2)
	{
		ifstream existe_propuestas_aceptadas;
		int propuestas_aceptadas;

		existe_propuestas_aceptadas.open(".\\Base de datos\\existe_propuestas_aceptadas.txt", ios::in);

		existe_propuestas_aceptadas >> propuestas_aceptadas;

		existe_propuestas_aceptadas.close();

		if (propuestas_aceptadas == 0)
		{
			cout << "No hay propuestas de trabajo que le hayan otorgado" << endl << endl;
		}
		else if (propuestas_aceptadas == 1)
		{
			ifstream nombre_trabajo;
			ifstream detalles_propuesta;
			string titulo;
			string detalles;
			int respuesta;

			nombre_trabajo.open(".\\Base de datos\\nombre_trabajo.txt", ios::in);
			detalles_propuesta.open(".\\Base de datos\\detalles_propuesta.txt", ios::in);

			getline(nombre_trabajo, titulo);
			getline(detalles_propuesta, detalles);

			nombre_trabajo.close();
			detalles_propuesta.close();

			cout << "Le otorgaron un trabajo para escribir un texto titulado: " << titulo << endl << endl;
			cout << "A continuacion se muestra la descripcion de lo que solicito el cliente que escriba" << endl << endl;
			cout << detalles << endl << endl;
			cout << "¿Quiere comenzar a escribir ahora?" << endl << "Ingrese 1: Para responer SI  /  Ingrese 2: Para responder NO" << endl;
			cin >> respuesta;
			cin.ignore();
			cout << endl;

			if (respuesta == 1)
			{
				ofstream texto;
				ofstream existe_propuestas_aceptadas;
				ofstream existe_texto_listo;
				string textocache;

				cout << "Por favor, a continuacion escriba el texto de su trabajo, recuerde que siendo esto una maqueta primitiva no puede usar el enter para bajar de renglon, si presiona enter se guardara lo que haya escrito y se cerrara el programa" << endl << endl;

				getline(cin, textocache);

				texto.open(".\\Base de datos\\texto.txt", ios::out);
				existe_propuestas_aceptadas.open(".\\Base de datos\\existe_propuestas_aceptadas.txt", ios::out);
				existe_texto_listo.open(".\\Base de datos\\existe_texto_listo.txt", ios::out);

				texto << textocache;
				existe_propuestas_aceptadas << 0;
				existe_texto_listo << 1;

				texto.close();
				existe_propuestas_aceptadas.close();
				existe_texto_listo.close();

				cout << endl << "Texto guardado con exito" << endl << endl;
			}
			else if (respuesta == 2)
			{
				abort;
			}
		}
	}
	else if (opcion_menu == 3)
	{
		cout << "Su valoracion como escritor es de 10/10 puntos\nSus comentarios son los siguientes: " << endl << endl;
		cout << "Comentarios..." << endl << endl;
	}
	else if (opcion_menu == 4)
	{
		cout << "Usted tiene 0 baneos confirmados por copiar texto de forma ilegal\nRecuerde que al 3er baneo su cuenta sera eliminada y sus datos no se podran usar nuevamente para crear otro usuario" << endl << endl;
	}
	else if (opcion_menu == 5)
	{
		abort;
	}
	else
	{
		cout << "Fatal error" << endl;
		abort;
	}
}
