// Leia quatro valores inteiros A, B, C e D. A seguir, calcule e mostre
// a diferença do produto de A e B pelo produto de C e D segundo a fórmula: DIFERENCA = (A * B - C * D).

// Entrada
// O arquivo de entrada contém 4 valores inteiros.

// Saída
// Imprima a mensagem DIFERENCA com todas as letras maiúsculas, conforme exemplo abaixo, com um espaço em branco antes e depois da igualdade.

import java.io.IOException;
import java.util.Scanner;

public class P1007 {
    public static void main(String[] args) throws IOException {
        Scanner leitor = new Scanner(System.in);
        int A = leitor.nextInt();
        int B = leitor.nextInt();
        int C = leitor.nextInt();
        int D = leitor.nextInt();

        int diferenca = (A * B) - (C * D);
        
        System.out.println("DIFERENCA = " + diferenca);
        leitor.close();
    }
}
