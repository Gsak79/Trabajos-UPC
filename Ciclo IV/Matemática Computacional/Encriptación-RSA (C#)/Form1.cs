
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using tp.control;

namespace tp
{
    public partial class Form1 : Form
    {
        int n;
        int nd;
        public Form1()
        {
            InitializeComponent();
            n = 0;
            nd = 0;
        }

        private void bt_Encriptar_Click(object sender, EventArgs e)
        {
            pa_Portada.Visible = false;
            pa_Encriptar.Visible = true;
        }

        private void bt_SeleccionarArchivoEncriptar_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                if (openFileDialog1.CheckFileExists == true)
                {
                    lb_rutaEncriptar.Text = openFileDialog1.FileName;

                    StreamReader ArchivoLeer = new StreamReader(openFileDialog1.FileName);
                    rtb_mensajeEncriptar.Text = ArchivoLeer.ReadToEnd();
                    ArchivoLeer.Close();
                }
            }
        }

        private void bt_regresarPortada_Click(object sender, EventArgs e)
        {
            rtb_mensajeEncriptar.Text = "";
            lb_rutaEncriptar.Text = "";
            pa_Encriptar.Visible = false;
            pa_Portada.Visible = true;
        }

        private void bt_EncriptarMensaje_Click(object sender, EventArgs e)
        {
            if (rtb_mensajeEncriptar.Text.Length == 0)
            {
                MessageBox.Show("No hay ningún mensaje para encriptar");
                return;
            }
            int numero1 = 0;
            int numero2 = 0;

            Controlador.AleatorioPrimo(ref numero1, ref numero2);

            n = numero1 * numero2;
            int euler = (numero1 - 1) * (numero2 - 1);

            nd = Controlador.CalcularD(euler);
            int ne = Controlador.CalcularE(nd, euler);

            string std_mensajeEncriptado = Controlador.EncriptarMensaje(rtb_mensajeEncriptar.Text, n, ne, rtb_mensajeEncriptar.Text.Length);

            if(std_mensajeEncriptado == "No disponible")
            {
                MessageBox.Show("El mensaje a encriptar tiene caracteres que no están disponible");
                return;
            }

            pa_Encriptar.Visible = false;
            pa_TextoEncriptado.Visible = true;

            rtb_mensajeEncriptar.Text = "";
            rtb_MensajeEncriptado.Text = std_mensajeEncriptado;

            lb_clavePrivada.Text = "Clave privada: (" + n + ", " + nd + ")";
        }

        private void bt_regresar_Click(object sender, EventArgs e)
        {
            rtb_MensajeEncriptado.Text = "";
            lb_rutaEncriptar.Text = "";
            pa_TextoEncriptado.Visible = false;
            pa_Encriptar.Visible = true;
        }

        private void bt_DescargarEncriptado_Click(object sender, EventArgs e)
        {
            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                if (saveFileDialog1.CheckPathExists == true)
                {
                    StreamWriter ArchivoEscribir = new StreamWriter(saveFileDialog1.FileName);
                    ArchivoEscribir.Write(rtb_MensajeEncriptado.Text + "Clave privada: (" + n + ", " + nd + ")");
                    ArchivoEscribir.Close();
                }
            }
        }

        private void bt_regresardesencriptar_Click(object sender, EventArgs e)
        {
            tb_d.Text = "";
            tb_n.Text = "";
            lb_rutaDesencriptar.Text = "";
            rtb_desencriptar.Text = "";
            pa_desencriptar.Visible = false;
            pa_Portada.Visible = true;
        }

        private void bt_SeleccionarDesencriptarArchivo_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                if (openFileDialog1.CheckFileExists == true)
                {
                    lb_rutaDesencriptar.Text = openFileDialog1.FileName;

                    StreamReader ArchivoLeer = new StreamReader(openFileDialog1.FileName);
                    rtb_desencriptar.Text = ArchivoLeer.ReadToEnd();
                    ArchivoLeer.Close();
                }
            }
        }

        private void bt_desencrip_Click(object sender, EventArgs e)
        {
            if(tb_d.Text.Length == 0 || tb_n.Text.Length == 0)
            {
                MessageBox.Show("No ha ingresado la clave privada correctamente");
                return;
            }
            if(rtb_desencriptar.Text.Length == 0)
            {
                MessageBox.Show("No hay ningún mensaje por desencriptar");
                return;
            }
            int n, d;
            int.TryParse(tb_n.Text, out n);
            int.TryParse(tb_d.Text, out d);

            if(n == 0 || d == 0)
            {
                MessageBox.Show("La clave privada ingresada tiene que contener solo números");
                return;
            }

            string mensaje = Controlador.DesencriptarMensaje(rtb_desencriptar.Text, n, d, rtb_desencriptar.Text.Length);

            if(mensaje == System.String.Empty)
            {
                MessageBox.Show("La clave privada o el mensaje encriptado ingresado es incorrecto \n\n - Asegúrese que el mensaje encriptado termine en un guión sin espacios");
                return;
            }

            rtb_MensajeDesencriptado.Text = mensaje;
            tb_d.Text = "";
            tb_n.Text = "";

            pa_desencriptar.Visible = false;
            pa_MensajeDesencriptado.Visible = true;
        }

        private void bt_Desencriptar_Click(object sender, EventArgs e)
        {
            pa_Portada.Visible = false;
            pa_desencriptar.Visible = true;
        }

        private void bt_descargardescriptado_Click(object sender, EventArgs e)
        {
            if (saveFileDialog2.ShowDialog() == DialogResult.OK)
            {
                if (saveFileDialog2.CheckPathExists == true)
                {
                    StreamWriter ArchivoEscribir = new StreamWriter(saveFileDialog2.FileName);
                    ArchivoEscribir.Write(rtb_MensajeDesencriptado.Text);
                    ArchivoEscribir.Close();
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            rtb_desencriptar.Text = "";
            lb_rutaDesencriptar.Text = "";
            pa_MensajeDesencriptado.Visible = false;
            pa_desencriptar.Visible = true;
        }

        private void bt_EnviarCorreo_Click(object sender, EventArgs e)
        {
            FormularioEmail frm = new FormularioEmail();
            
            frm.ShowDialog();
            
            if (frm.getEnviar() == false) { return; } 
            try
            {
                System.Net.Mail.MailMessage msg = new System.Net.Mail.MailMessage();
                msg.To.Add(frm.tb_correoDes.Text);
                msg.Subject = "Archivo encriptado + clave privada";
                msg.SubjectEncoding = System.Text.Encoding.UTF8;

                msg.Body = rtb_MensajeEncriptado.Text + "   Clave privada: (" + n + ", " + nd + ")";
                msg.BodyEncoding = System.Text.Encoding.UTF8;
                msg.IsBodyHtml = false;
                msg.From = new System.Net.Mail.MailAddress(frm.tb_correoDes.Text);

                System.Net.Mail.SmtpClient cliente = new System.Net.Mail.SmtpClient();

                cliente.Credentials = new System.Net.NetworkCredential(frm.tb_correoRem.Text, frm.tb_contraseñaRem.Text);
                cliente.Port = 587;
                cliente.EnableSsl = true;
                cliente.Host = "smtp.gmail.com";
                cliente.Send(msg);
                MessageBox.Show("El mensaje se envió correctamente");
            }
            catch (Exception)
            {
                MessageBox.Show("Hubo un error al enviar el mensaje. \n\n Asegurese en tener en cuenta lo siguiente: \n\n 1. El correo electrónico o la contraseña ingresada son incorrectos. \n\n 2. Asegurese de que su cuenta de correo electrónico este activado la opción de acceso a aplicaciones poco seguras. \n\n 3. Debe tener conexión a internet estable.");
            }
        }
    }
}
