import java.io.IOException;
import java.util.Scanner;

public class Main {
    // // P1000
    // public static void main(String[] args) throws IOException {
    // System.out.println("Hello World!");
    // }

    // // P1001
    // public static void main(String[] args) throws IOException {
    // Scanner input = new Scanner(System.in);
    // int a = input.nextInt();
    // int b = input.nextInt();
    // System.out.println("X = " + (a + b));
    // input.close();
    // }

    // // P1002
    // public static void main(String[] args) throws IOException {
    // Scanner input = new Scanner(System.in);
    // double raio = input.nextDouble();
    // double area = 3.14159 * Math.pow(raio, 2);
    // System.out.printf("A=%.4f\n", area);
    // input.close();
    // }

    // // P1003
    // public static void main(String[] args) throws IOException {
    // Scanner input = new Scanner(System.in);
    // int a = input.nextInt();
    // int b = input.nextInt();
    // int soma = a + b;
    // System.out.println("SOMA = " + soma);
    // input.close();
    // }

    // // P1004
    // public static void main(String[] args) throws IOException {
    // Scanner input = new Scanner(System.in);
    // int a = input.nextInt();
    // int b = input.nextInt();
    // int prod = a * b;
    // System.out.println("PROD = " + prod);
    // input.close();
    // }

    // // P1005
    // public static void main(String[] args) throws IOException {
    // Scanner input = new Scanner(System.in);
    // double a = input.nextDouble();
    // double b = input.nextDouble();
    // double media = ((a * 3.5) + (b * 7.5)) / 11;
    // System.out.printf("MEDIA = %.5f\n", media);
    // input.close();
    // }

    // // P1006
    // public static void main(String[] args) throws IOException {
    // Scanner input = new Scanner(System.in);
    // double a = input.nextDouble();
    // double b = input.nextDouble();
    // double c = input.nextDouble();
    // double media = ((a * 2) + (b * 3) + (c * 5)) / 10;
    // System.out.printf("MEDIA = %.1f\n", media);
    // input.close();
    // }

    // // P1007
    // public static void main(String[] args) throws IOException {
    // Scanner leitor = new Scanner(System.in);
    // int A = leitor.nextInt();
    // int B = leitor.nextInt();
    // int C = leitor.nextInt();
    // int D = leitor.nextInt();
    // int diferenca = (A * B) - (C * D);
    // System.out.println("DIFERENCA = " + diferenca);
    // leitor.close();
    // }

    // // P1008
    // public static void main(String[] args) throws IOException {
    // Scanner leitor = new Scanner(System.in);
    // int numero = leitor.nextInt();
    // int horas = leitor.nextInt();
    // double valor = leitor.nextDouble();
    // double salario = horas * valor;
    // System.out.println("NUMBER = " + numero);
    // System.out.printf("SALARY = U$ %.2f\n",salario);
    // leitor.close();
    // }

    // // P1009
    // public static void main(String[] args) throws IOException {
    // Scanner leitor = new Scanner(System.in);
    // @SuppressWarnings("unused")
    // String nome = leitor.next();
    // double salario = leitor.nextDouble();
    // double vendas = leitor.nextDouble();
    // double comissao = vendas * 0.15;
    // double total = (salario + comissao);
    // System.out.println("TOTAL = R$ " + String.format("%.2f", total));
    // leitor.close();
    // }

    // // P1010
    // public static void main(String[] args) throws IOException {
    // Scanner leitor = new Scanner(System.in);
    // @SuppressWarnings("unused")
    // int cod1 = leitor.nextInt();
    // int n1 = leitor.nextInt();
    // double v1 = leitor.nextDouble();
    // @SuppressWarnings("unused")
    // int cod2 = leitor.nextInt();
    // int n2 = leitor.nextInt();
    // double v2 = leitor.nextDouble();
    // double total = n1 * v1 + n2 * v2;
    // System.out.printf("VALOR A PAGAR: R$ %.2f\n", total);
    // leitor.close();
    // }

    // // P1011
    // public static void main(String[] args) throws IOException {
    // Scanner leitor = new Scanner(System.in);
    // double R = leitor.nextDouble();
    // double pi = 3.14159;
    // double volume = (4.0 / 3) * pi * Math.pow(R, 3);
    // System.out.printf("VOLUME = %.3f\n", volume);
    // leitor.close();
    // }

    // // P1012
    // public static void main(String[] args) throws IOException {
    // Scanner leitor = new Scanner(System.in);
    // double A = leitor.nextDouble();
    // double B = leitor.nextDouble();
    // double C = leitor.nextDouble();
    // double triangulo = (A * C) / 2;
    // double circulo = 3.14159 * (Math.pow(C, 2));
    // double trapezio = ((A + B) * C) / 2;
    // double quadrado = Math.pow(B, 2);
    // double retangulo = A * B;
    // System.out.printf("TRIANGULO: %.3f\n", triangulo);
    // System.out.printf("CIRCULO: %.3f\n", circulo);
    // System.out.printf("TRAPEZIO: %.3f\n", trapezio);
    // System.out.printf("QUADRADO: %.3f\n", quadrado);
    // System.out.printf("RETANGULO: %.3f\n", retangulo);
    // leitor.close();
    // }

    // // P1013
    // public static void main(String[] args) throws IOException {
    // Scanner leitor = new Scanner(System.in);
    // int A = leitor.nextInt();
    // int B = leitor.nextInt();
    // int C = leitor.nextInt();

    // float maiorAB = (A + B + Math.abs(A - B)) / 2;
    // float maiorABC = (maiorAB + C + Math.abs(maiorAB - C)) / 2;

    // System.out.println((int) maiorABC + " eh o maior");
    // leitor.close();
    // }

    // // P1014
    // public static void main(String[] args) throws IOException {
    // Scanner leitor = new Scanner(System.in);
    // int X = leitor.nextInt();
    // double Y = leitor.nextDouble();
    // double media = X / Y;
    // System.out.printf("%.3f km/l\n", media);
    // leitor.close();
    // }

    // // P1015
    // public static void main(String[] args) throws IOException {
    // Scanner leitor = new Scanner(System.in);
    // double x1 = leitor.nextDouble();
    // double y1 = leitor.nextDouble();
    // double x2 = leitor.nextDouble();
    // double y2 = leitor.nextDouble();
    // double dist = Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
    // System.out.printf("%.4f\n", dist);
    // leitor.close();
    // }

    // // P1016
    // public static void main(String[] args) throws IOException {
    // Scanner leitor = new Scanner(System.in);
    // int dist = leitor.nextInt();
    // int tempo = dist * 2;
    // System.out.println(tempo + " minutos");
    // leitor.close();
    // }

    // // P1017
    // public static void main(String[] args) throws IOException {
    // Scanner leitor = new Scanner(System.in);
    // int tempo = leitor.nextInt();
    // int velocidade = leitor.nextInt();
    // double litros = (tempo * velocidade) / 12.0;
    // System.out.printf("%.3f\n", litros);
    // leitor.close();
    // }

    // // P1018
    // public static void main(String[] args) throws IOException {
    // Scanner leitor = new Scanner(System.in);
    // int N = leitor.nextInt();
    // int nota100 = N / 100;
    // int nota50 = (N % 100) / 50;
    // int nota20 = ((N % 100) % 50) / 20;
    // int nota10 = (((N % 100) % 50) % 20) / 10;
    // int nota5 = ((((N % 100) % 50) % 20) % 10) / 5;
    // int nota2 = (((((N % 100) % 50) % 20) % 10) % 5) / 2;
    // int nota1 = ((((((N % 100) % 50) % 20) % 10) % 5) % 2) / 1;
    // System.out.println(N);
    // System.out.println(nota100 + " nota(s) de R$ 100,00");
    // System.out.println(nota50 + " nota(s) de R$ 50,00");
    // System.out.println(nota20 + " nota(s) de R$ 20,00");
    // System.out.println(nota10 + " nota(s) de R$ 10,00");
    // System.out.println(nota5 + " nota(s) de R$ 5,00");
    // System.out.println(nota2 + " nota(s) de R$ 2,00");
    // System.out.println(nota1 + " nota(s) de R$ 1,00");
    // leitor.close();
    // }

    // // P1019
    // public static void main(String[] args) throws IOException {
    // Scanner leitor = new Scanner(System.in);
    // int N = leitor.nextInt();
    // int horas = N / 3600;
    // int minutos = (N % 3600) / 60;
    // int segundos = (N % 3600) % 60;
    // System.out.println(horas + ":" + minutos + ":" + segundos);
    // leitor.close();
    // }

    // // P1020
    // Leia um valor inteiro correspondente à idade de uma pessoa em dias e
    // informe-a em anos, meses e dias

    // Obs.: apenas para facilitar o cálculo, considere todo ano com 365 dias e todo
    // mês com 30 dias. Nos casos de teste nunca haverá uma situação que permite 12
    // meses e alguns dias, como 360, 363 ou 364. Este é apenas um exercício com
    // objetivo de testar raciocínio matemático simples.

    // Entrada
    // O arquivo de entrada contém um valor inteiro.

    // Saída
    // Imprima a saída conforme exemplo fornecido.
    public static void main(String[] args) throws IOException {
        Scanner leitor = new Scanner(System.in);
        int N = leitor.nextInt();
        int anos = N / 365;
        int meses = (N % 365) / 30;
        int dias = (N % 365) % 30;
        System.out.println(anos + " ano(s)");
        System.out.println(meses + " mes(es)");
        System.out.println(dias + " dia(s)");
        leitor.close();
    }
}
