import java.util.Scanner;

public class Calculadora {

	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int operacion; 
		int numero1, numero2;
		
		System.out.println("Ingrese un numero: ");
		numero1 = scanner.nextInt();
		
		System.out.println("Ingrese otro numero: ");
		numero2 = scanner.nextInt();
		
		
		System.out.println("-Para realizar una suma ingrese el numero 1\n-Para realizar una resta ingrese el numero 2\nPara realizar una multiplicacion ingrese el numero 3\n-Para realizar una division ingrese el numero 4");
		operacion = scanner.nextInt();
		
		if(operacion == 1)
		{
			numero1 += numero2;
		}
		else if (operacion == 2)
		{
			numero1 -= numero2;
		}
		else if(operacion == 3)
		{
			numero1 = numero1 * numero2;
		}
		else if(operacion == 4)
		{
			numero1 = numero1 / numero2;
		}
		else
		{
			System.out.println("El numero ingresado no es valido.");
		}
			
		System.out.println("El resultado es " + numero1);	
		
		scanner.close(); 
	}

}
