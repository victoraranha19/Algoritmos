import java.util.Stack;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;

public class HtmlAnalyzer {
    public static void main(String[] args) {
        try {
            // Cria uma URL
            URL url = new URL(args[0]);

            // Abre uma conexão com a URL
            URLConnection urlConnection = url.openConnection();

            // Cria um BufferedReader para ler o conteúdo da URL
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(urlConnection.getInputStream()));

            // Analiza o HTML para encontrar o texto contido no nível mais profundo
            String inputLine, deeperLevelStr="";
            Stack<String> tagsHtml = new Stack<>();
            int level=0, deeperLevel=0;

            while ((inputLine = bufferedReader.readLine()) != null) {
                String line = inputLine.trim();
                if (line.startsWith("</") && line.endsWith(">")) {
                    // Verifica se a tag mais alta está sendo fechada
                    if (tagsHtml.empty()) {
                        deeperLevel = -1; // malformed HTML
                        break;
                    }
                    String poppedTag = tagsHtml.pop();
                    if (line.substring(2, line.length()-1).equals(poppedTag)) {
                        level--;
                    }
                    else {
                        deeperLevel = -2; // malformed HTML
                        break;
                    }
                }
                else if (line.startsWith("<") && line.endsWith(">")) {
                    // Adicona a tag na pilha (descartando os atributos)
                    //String[] pushedTag = line.substring(1, line.length()-1).split(" ", 2);
                    //tagsHtml.push(pushedTag[0]);

                    // Adiciona a tag na pilha (considerando que não possui atributos)
                    tagsHtml.push(line.substring(1, line.length()-1));
                    level++;
                }
                else {
                    // Armazena o conteúdo mais profundo
                    if (level > deeperLevel) {
                        deeperLevelStr = line;
                        deeperLevel = level;
                    }
                }
            }

            // Fecha o BufferedReader
            bufferedReader.close();

            // Imprime o texto contido no nível mais profundo
            if (deeperLevel > 0) {
                System.out.println(deeperLevelStr);
            }
            else {
                System.out.println("malformed HTML");
            }

        } catch (IOException e) {
            System.out.println("URL Connection Error");
        }
    }
}