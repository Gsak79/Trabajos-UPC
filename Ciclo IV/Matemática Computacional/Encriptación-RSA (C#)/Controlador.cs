using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace tp.control
{
    public class Controlador
    {
        static readonly char[] codigo_alfa = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'ñ', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ', '.', ',', 'á', 'é', 'í', 'ó', 'ú', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'Ñ', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '!', '"', '#', '$', '%', '&', '/', '(', ')', '=', '?', '¿', '¡', '´', '+', '*', '~', '|', '°', '¬', '@', '¨', '{', '[', '^', '}', ']', '`', '-', '_', '\\', '<', '>', ':', ';', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
        static public int CalcularD(int euler)
        {
            int d;
            Random aleatorio = new Random();
            do
            {
                d = aleatorio.Next(2, 100000);
            } while (MCD(d, euler) != 1 || d > euler);
            return d;
        }

        static public int CalcularE(int d, int euler)
        {
            int e = 0;
            for (int i = 2; i < 99999; i++)
            {
                if ((d * i - 1) % euler == 0)
                {
                    e = i;
                    return e;
                }
            }
            return e;
        }

        static bool EsPrimo(int num)
        {
            for (short i = 2; i < num; i++)
            {
                if (num % i == 0) { return false; }
            }
            return true;
        }

        static public void AleatorioPrimo(ref int num1, ref int num2)
        {
            Random aleatorio = new Random();
            do
            {
                num1 = aleatorio.Next(2, 50);
                num2 = aleatorio.Next(2, 50);
            } while (EsPrimo(num1) == false || num1 == num2 || EsPrimo(num2) == false || num1 * num2 < 107);
        }

        static int MCD(int num1, int num2)
        {
            int res;
            if (num2 > num1)
            {
                int aux;
                aux = num1;
                num1 = num2;
                num2 = aux;
            }
            if (num1 % num2 == 0) return num1;
            else res = num1 % num2;

            do
            {
                num1 = num2;
                num2 = res;
                res = num1 % num2;

            } while (res != 0);

            return num2;
        }

        static public string EncriptarMensaje(string mensaje, int n, int ne, int cantidad)
        {
            string mensajeEncriptado = "";
            int index = 0;
            for (int i = 0; i < cantidad; i++)
            {
                for (short j = 0; j < 107; j++)
                {
                    if (mensaje[i] == codigo_alfa[j])
                    {
                        index = j;
                        break;
                    }
                    else if(j == 106)
                    {
                        return "No disponible";
                    }
                }

                BigInteger potencia = BigInteger.Pow(index, ne);
                BigInteger codigo = potencia % n;

                mensajeEncriptado += codigo + "-";
            }
            return mensajeEncriptado;
        }

        static public string DesencriptarMensaje(string mensaje, int n, int d, int cantidad)
        {
            string mensajeDesencriptado = "";
            
            for (int i = 0; i < cantidad; i++)
            {
                string numero = "";
                for (int j = i; mensaje[j] != '-' && j < cantidad - 1; j++)
                {
                    numero += mensaje[j];
                    i++;
                }
                int index;
                bool num = int.TryParse(numero, out index);
                if(num == false)
                {
                    return System.String.Empty;
                }
                BigInteger potencia = BigInteger.Pow(index, d);
                BigInteger codigo = potencia % n;

                if(codigo < 0 || codigo > 107)
                {
                    return System.String.Empty;
                }

                mensajeDesencriptado += codigo_alfa[(int)codigo];
            }
            return mensajeDesencriptado;
        }

    }
};


