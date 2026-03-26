#include <iostream>
#include <string>
#include "curp/curp.hpp"

using namespace std;

void printMenu();
void printDivider();
void printHeader(const string& title);

int main(void) {
  int quantity = 0;
  int selection = 0;
  bool quit = false;
  CURP instance;

  printHeader("CRUD de CURPs");

  // Carga inicial
  cout << "\n  Ingrese la cantidad de CURPs a registrar inicialmente: ";
  do {
    cin >> quantity;
    if (quantity <= 0)
      cout << "  [!] Debe ingresar un numero mayor a 0: ";
  } while (quantity <= 0);

  cout << "\n";

  for (int i = 0; i < quantity; i++) {
    string curp = "";
    bool success = false;
    do {
      cout << "  CURP [" << i + 1 << "/" << quantity << "]: ";
      cin >> curp;

      if (curp.length() != 18) {
        cout << "  [!] El CURP debe tener exactamente 18 caracteres.\n";
        success = false;
      } else {
        success = instance.addCurp(curp);
        if (!success)
          cout << "  [!] Ese CURP ya esta registrado.\n";
      }
    } while (!success);
  }

  cout << "\n  " << quantity << " CURP(s) registrado(s) correctamente.\n";

  // Menu principal
  do {
    cout << "\n";
    do {
      printMenu();
      cout << "  Opcion: ";
      cin >> selection;
      if (selection < 1 || selection > 6)
        cout << "  [!] Seleccion invalida. Intente de nuevo.\n";
    } while (selection < 1 || selection > 6);

    cout << "\n";

    switch (selection) {

      case 1: {
        printHeader("Agregar CURP");
        string curp = "";
        bool success = false;
        do {
          cout << "  Ingrese el CURP a agregar: ";
          cin >> curp;

          if (curp.length() != 18) {
            cout << "  [!] El CURP debe tener exactamente 18 caracteres.\n";
            success = false;
          } else {
            success = instance.addCurp(curp);
            if (!success)
              cout << "  [!] Ese CURP ya esta registrado.\n";
          }
        } while (!success);

        cout << "  [OK] CURP registrado exitosamente.\n";
        break;
      }

      case 2: {
        printHeader("Lista de CURPs");
        auto curps = instance.getCurps();
        if (curps.empty()) {
          cout << "  No hay CURPs registrados.\n";
        } else {
          cout << "\n";
          int i = 1;
          for (const auto& curp : curps) {
            cout << "  " << i++ << ". " << curp << "\n";
          }
          cout << "\n  Total: " << curps.size() << " CURP(s).\n";
        }
        break;
      }

      case 3: {
        printHeader("Buscar CURP");
        string curp;
        cout << "  Ingrese el CURP a buscar: ";
        cin >> curp;

        string found = instance.findCurp(curp);
        if (found != curp) {
          cout << "  [!] El CURP ingresado no esta registrado.\n";
        } else {
          cout << "  [OK] CURP encontrado: " << found << "\n";
        }
        break;
      }

      case 4: {
        printHeader("Modificar CURP");
        string oldCurp = "", newCurp = "";

        cout << "  Ingrese el CURP a modificar:    ";
        cin >> oldCurp;

        bool success = false;
        do {
          cout << "  Ingrese el nuevo CURP:          ";
          cin >> newCurp;

          if (newCurp.length() != 18) {
            cout << "  [!] El CURP debe tener exactamente 18 caracteres.\n";
            success = false;
          } else {
            success = instance.updateCurp(oldCurp, newCurp);
            if (!success)
              cout << "  [!] El CURP original no existe o el nuevo ya esta registrado.\n";
          }
        } while (!success);

        cout << "  [OK] CURP modificado correctamente.\n";
        break;
      }

      case 5: {
        printHeader("Eliminar CURP");
        string curp = "";
        cout << "  Ingrese el CURP a eliminar: ";
        cin >> curp;

        bool success = instance.deleteCurp(curp);
        if (!success) {
          cout << "  [!] El CURP ingresado no existe.\n";
        } else {
          cout << "  [OK] CURP eliminado exitosamente.\n";
        }
        break;
      }

      case 6:
        printDivider();
        cout << "  Hasta luego.\n";
        printDivider();
        quit = true;
        break;
    }

  } while (!quit);

  return 0;
}

void printDivider() {
  cout << "  ----------------------------------------\n";
}

void printHeader(const string& title) {
  printDivider();
  cout << "  " << title << "\n";
  printDivider();
}

void printMenu() {
  printDivider();
  cout << "  MENU PRINCIPAL\n";
  printDivider();
  cout << "  1. Agregar CURP\n";
  cout << "  2. Consultar todos los CURPs\n";
  cout << "  3. Buscar un CURP especifico\n";
  cout << "  4. Modificar un CURP\n";
  cout << "  5. Eliminar un CURP\n";
  cout << "  6. Salir\n";
  printDivider();
}
