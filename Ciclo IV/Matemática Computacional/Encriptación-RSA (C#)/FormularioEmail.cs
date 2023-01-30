using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace tp
{
    public partial class FormularioEmail : Form
    {
        bool enviar;
        public FormularioEmail()
        {
            InitializeComponent();
        }

        private void bt_enviar_Click(object sender, EventArgs e)
        {
            if(tb_contraseñaRem.Text.Length == 0 || tb_correoDes.Text.Length == 0 || tb_correoRem.Text.Length == 0)
            {
                MessageBox.Show("Algunos de los campos están vacios");
                return;
            }
            enviar = true;
            this.Close();
        }

        private void bt_RegresarEmail_Click(object sender, EventArgs e)
        {
            enviar = false;
            this.Close();
        }
        public bool getEnviar()
        {
            return enviar;
        }
    }
}
