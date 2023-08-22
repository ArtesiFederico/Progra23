package Primer;

import java.util.Scanner;



public class CienPrimo {

public static void main(String args[]) {
       Scanner scanner = new Scanner(System.in);
       int numero;
       
       do {
           
       System.out.println("Ingrese un numero: ");
       numero = scanner.nextInt();
       
       }while (numero < 100);
       
           
       System.out.println("El numero que ingreso es mayor que 100!");    
       
       scanner.close();
   }
}
