// Leia dois valores inteiros.
// A seguir, calcule o produto entre estes dois valores e atribua esta operação à variável PROD.
// A seguir mostre a variável PROD com mensagem correspondente.   

// Entrada
// O arquivo de entrada contém 2 valores inteiros.

// Saída
// Imprima a mensagem "PROD" e a variável PROD conforme exemplo abaixo,
// com um espaço em branco antes e depois da igualdade. Não esqueça de imprimir
// o fim de linha após o produto, caso contrário seu programa apresentará
// a mensagem: “Presentation Error”.

import java.io.IOException;
import java.util.Scanner;

public class P1004 {
    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        int b = input.nextInt();
        int prod = a * b;
        System.out.println("PROD = " + prod);
        input.close();
    }
}
