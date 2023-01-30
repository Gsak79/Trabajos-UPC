namespace tp
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.pa_Portada = new System.Windows.Forms.Panel();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.bt_Desencriptar = new System.Windows.Forms.Button();
            this.bt_Encriptar = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.pa_Encriptar = new System.Windows.Forms.Panel();
            this.bt_regresarPortada = new System.Windows.Forms.Button();
            this.bt_EncriptarMensaje = new System.Windows.Forms.Button();
            this.rtb_mensajeEncriptar = new System.Windows.Forms.RichTextBox();
            this.lb_rutaEncriptar = new System.Windows.Forms.Label();
            this.bt_SeleccionarArchivoEncriptar = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.pa_TextoEncriptado = new System.Windows.Forms.Panel();
            this.bt_EnviarCorreo = new System.Windows.Forms.Button();
            this.bt_DescargarEncriptado = new System.Windows.Forms.Button();
            this.bt_regresar = new System.Windows.Forms.Button();
            this.lb_clavePrivada = new System.Windows.Forms.Label();
            this.rtb_MensajeEncriptado = new System.Windows.Forms.RichTextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.pa_desencriptar = new System.Windows.Forms.Panel();
            this.lb_rutaDesencriptar = new System.Windows.Forms.Label();
            this.bt_SeleccionarDesencriptarArchivo = new System.Windows.Forms.Button();
            this.bt_regresardesencriptar = new System.Windows.Forms.Button();
            this.label8 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.bt_desencrip = new System.Windows.Forms.Button();
            this.tb_n = new System.Windows.Forms.TextBox();
            this.tb_d = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.rtb_desencriptar = new System.Windows.Forms.RichTextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.pa_MensajeDesencriptado = new System.Windows.Forms.Panel();
            this.bt_descargardescriptado = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.rtb_MensajeDesencriptado = new System.Windows.Forms.RichTextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.saveFileDialog2 = new System.Windows.Forms.SaveFileDialog();
            this.pa_Portada.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.pa_Encriptar.SuspendLayout();
            this.pa_TextoEncriptado.SuspendLayout();
            this.pa_desencriptar.SuspendLayout();
            this.pa_MensajeDesencriptado.SuspendLayout();
            this.SuspendLayout();
            // 
            // pa_Portada
            // 
            this.pa_Portada.BackColor = System.Drawing.Color.White;
            this.pa_Portada.BackgroundImage = global::tp.Properties.Resources.Fondo_azul;
            this.pa_Portada.Controls.Add(this.pictureBox2);
            this.pa_Portada.Controls.Add(this.pictureBox1);
            this.pa_Portada.Controls.Add(this.bt_Desencriptar);
            this.pa_Portada.Controls.Add(this.bt_Encriptar);
            this.pa_Portada.Controls.Add(this.label1);
            this.pa_Portada.Location = new System.Drawing.Point(0, 0);
            this.pa_Portada.Name = "pa_Portada";
            this.pa_Portada.Size = new System.Drawing.Size(1100, 575);
            this.pa_Portada.TabIndex = 2;
            // 
            // pictureBox2
            // 
            this.pictureBox2.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox2.Image = global::tp.Properties.Resources.Desencriptar;
            this.pictureBox2.Location = new System.Drawing.Point(672, 144);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(278, 291);
            this.pictureBox2.TabIndex = 4;
            this.pictureBox2.TabStop = false;
            // 
            // pictureBox1
            // 
            this.pictureBox1.BackColor = System.Drawing.Color.Transparent;
            this.pictureBox1.Image = global::tp.Properties.Resources.Encriptar;
            this.pictureBox1.Location = new System.Drawing.Point(215, 144);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(272, 301);
            this.pictureBox1.TabIndex = 3;
            this.pictureBox1.TabStop = false;
            // 
            // bt_Desencriptar
            // 
            this.bt_Desencriptar.BackColor = System.Drawing.SystemColors.Control;
            this.bt_Desencriptar.Font = new System.Drawing.Font("UD Digi Kyokasho NP-B", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.bt_Desencriptar.Location = new System.Drawing.Point(602, 451);
            this.bt_Desencriptar.Name = "bt_Desencriptar";
            this.bt_Desencriptar.Size = new System.Drawing.Size(373, 70);
            this.bt_Desencriptar.TabIndex = 2;
            this.bt_Desencriptar.Text = "Desencriptar";
            this.bt_Desencriptar.UseVisualStyleBackColor = false;
            this.bt_Desencriptar.Click += new System.EventHandler(this.bt_Desencriptar_Click);
            // 
            // bt_Encriptar
            // 
            this.bt_Encriptar.BackColor = System.Drawing.SystemColors.Control;
            this.bt_Encriptar.Font = new System.Drawing.Font("UD Digi Kyokasho NP-B", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.bt_Encriptar.Location = new System.Drawing.Point(143, 451);
            this.bt_Encriptar.Name = "bt_Encriptar";
            this.bt_Encriptar.Size = new System.Drawing.Size(373, 70);
            this.bt_Encriptar.TabIndex = 1;
            this.bt_Encriptar.Text = "Encriptar";
            this.bt_Encriptar.UseVisualStyleBackColor = false;
            this.bt_Encriptar.Click += new System.EventHandler(this.bt_Encriptar_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.Font = new System.Drawing.Font("Oswald", 28.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.SystemColors.Control;
            this.label1.Location = new System.Drawing.Point(303, 34);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(419, 71);
            this.label1.TabIndex = 0;
            this.label1.Text = "La encriptación RSA";
            // 
            // pa_Encriptar
            // 
            this.pa_Encriptar.BackgroundImage = global::tp.Properties.Resources.Fondo_azul;
            this.pa_Encriptar.Controls.Add(this.bt_regresarPortada);
            this.pa_Encriptar.Controls.Add(this.bt_EncriptarMensaje);
            this.pa_Encriptar.Controls.Add(this.rtb_mensajeEncriptar);
            this.pa_Encriptar.Controls.Add(this.lb_rutaEncriptar);
            this.pa_Encriptar.Controls.Add(this.bt_SeleccionarArchivoEncriptar);
            this.pa_Encriptar.Controls.Add(this.label2);
            this.pa_Encriptar.Location = new System.Drawing.Point(0, 0);
            this.pa_Encriptar.Name = "pa_Encriptar";
            this.pa_Encriptar.Size = new System.Drawing.Size(1100, 537);
            this.pa_Encriptar.TabIndex = 6;
            this.pa_Encriptar.Visible = false;
            // 
            // bt_regresarPortada
            // 
            this.bt_regresarPortada.Location = new System.Drawing.Point(891, 20);
            this.bt_regresarPortada.Name = "bt_regresarPortada";
            this.bt_regresarPortada.Size = new System.Drawing.Size(175, 47);
            this.bt_regresarPortada.TabIndex = 7;
            this.bt_regresarPortada.Text = "Regresar";
            this.bt_regresarPortada.UseVisualStyleBackColor = true;
            this.bt_regresarPortada.Click += new System.EventHandler(this.bt_regresarPortada_Click);
            // 
            // bt_EncriptarMensaje
            // 
            this.bt_EncriptarMensaje.Location = new System.Drawing.Point(437, 461);
            this.bt_EncriptarMensaje.Name = "bt_EncriptarMensaje";
            this.bt_EncriptarMensaje.Size = new System.Drawing.Size(255, 52);
            this.bt_EncriptarMensaje.TabIndex = 4;
            this.bt_EncriptarMensaje.Text = "Encriptar mensaje";
            this.bt_EncriptarMensaje.UseVisualStyleBackColor = true;
            this.bt_EncriptarMensaje.Click += new System.EventHandler(this.bt_EncriptarMensaje_Click);
            // 
            // rtb_mensajeEncriptar
            // 
            this.rtb_mensajeEncriptar.Location = new System.Drawing.Point(12, 124);
            this.rtb_mensajeEncriptar.Name = "rtb_mensajeEncriptar";
            this.rtb_mensajeEncriptar.Size = new System.Drawing.Size(1064, 318);
            this.rtb_mensajeEncriptar.TabIndex = 3;
            this.rtb_mensajeEncriptar.Text = "";
            // 
            // lb_rutaEncriptar
            // 
            this.lb_rutaEncriptar.AutoSize = true;
            this.lb_rutaEncriptar.BackColor = System.Drawing.Color.Transparent;
            this.lb_rutaEncriptar.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lb_rutaEncriptar.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.lb_rutaEncriptar.Location = new System.Drawing.Point(215, 80);
            this.lb_rutaEncriptar.Name = "lb_rutaEncriptar";
            this.lb_rutaEncriptar.Size = new System.Drawing.Size(0, 20);
            this.lb_rutaEncriptar.TabIndex = 2;
            // 
            // bt_SeleccionarArchivoEncriptar
            // 
            this.bt_SeleccionarArchivoEncriptar.Location = new System.Drawing.Point(19, 70);
            this.bt_SeleccionarArchivoEncriptar.Name = "bt_SeleccionarArchivoEncriptar";
            this.bt_SeleccionarArchivoEncriptar.Size = new System.Drawing.Size(190, 42);
            this.bt_SeleccionarArchivoEncriptar.TabIndex = 1;
            this.bt_SeleccionarArchivoEncriptar.Text = "Seleccionar archivo";
            this.bt_SeleccionarArchivoEncriptar.UseVisualStyleBackColor = true;
            this.bt_SeleccionarArchivoEncriptar.Click += new System.EventHandler(this.bt_SeleccionarArchivoEncriptar_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.Color.Transparent;
            this.label2.Font = new System.Drawing.Font("Microsoft YaHei UI", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.label2.Location = new System.Drawing.Point(12, 20);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(348, 37);
            this.label2.TabIndex = 0;
            this.label2.Text = "Mensaje para encriptar:";
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.Filter = "Archivos de texto (*.txt)|*.txt";
            // 
            // saveFileDialog1
            // 
            this.saveFileDialog1.FileName = "Archivo Encriptado";
            this.saveFileDialog1.Filter = "Archivos de texto (*.txt)|*.txt";
            // 
            // pa_TextoEncriptado
            // 
            this.pa_TextoEncriptado.BackgroundImage = global::tp.Properties.Resources.Fondo_azul;
            this.pa_TextoEncriptado.Controls.Add(this.bt_EnviarCorreo);
            this.pa_TextoEncriptado.Controls.Add(this.bt_DescargarEncriptado);
            this.pa_TextoEncriptado.Controls.Add(this.bt_regresar);
            this.pa_TextoEncriptado.Controls.Add(this.lb_clavePrivada);
            this.pa_TextoEncriptado.Controls.Add(this.rtb_MensajeEncriptado);
            this.pa_TextoEncriptado.Controls.Add(this.label3);
            this.pa_TextoEncriptado.Location = new System.Drawing.Point(0, 0);
            this.pa_TextoEncriptado.Name = "pa_TextoEncriptado";
            this.pa_TextoEncriptado.Size = new System.Drawing.Size(1100, 534);
            this.pa_TextoEncriptado.TabIndex = 8;
            this.pa_TextoEncriptado.Visible = false;
            // 
            // bt_EnviarCorreo
            // 
            this.bt_EnviarCorreo.Location = new System.Drawing.Point(793, 445);
            this.bt_EnviarCorreo.Name = "bt_EnviarCorreo";
            this.bt_EnviarCorreo.Size = new System.Drawing.Size(283, 59);
            this.bt_EnviarCorreo.TabIndex = 15;
            this.bt_EnviarCorreo.Text = "Enviar correo electrónico";
            this.bt_EnviarCorreo.UseVisualStyleBackColor = true;
            this.bt_EnviarCorreo.Click += new System.EventHandler(this.bt_EnviarCorreo_Click);
            // 
            // bt_DescargarEncriptado
            // 
            this.bt_DescargarEncriptado.Location = new System.Drawing.Point(493, 445);
            this.bt_DescargarEncriptado.Name = "bt_DescargarEncriptado";
            this.bt_DescargarEncriptado.Size = new System.Drawing.Size(283, 59);
            this.bt_DescargarEncriptado.TabIndex = 14;
            this.bt_DescargarEncriptado.Text = "Descargar archivo";
            this.bt_DescargarEncriptado.UseVisualStyleBackColor = true;
            this.bt_DescargarEncriptado.Click += new System.EventHandler(this.bt_DescargarEncriptado_Click);
            // 
            // bt_regresar
            // 
            this.bt_regresar.Location = new System.Drawing.Point(891, 23);
            this.bt_regresar.Name = "bt_regresar";
            this.bt_regresar.Size = new System.Drawing.Size(175, 47);
            this.bt_regresar.TabIndex = 6;
            this.bt_regresar.Text = "Regresar";
            this.bt_regresar.UseVisualStyleBackColor = true;
            this.bt_regresar.Click += new System.EventHandler(this.bt_regresar_Click);
            // 
            // lb_clavePrivada
            // 
            this.lb_clavePrivada.AutoSize = true;
            this.lb_clavePrivada.BackColor = System.Drawing.Color.Transparent;
            this.lb_clavePrivada.Font = new System.Drawing.Font("Microsoft YaHei UI", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lb_clavePrivada.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.lb_clavePrivada.Location = new System.Drawing.Point(28, 445);
            this.lb_clavePrivada.Name = "lb_clavePrivada";
            this.lb_clavePrivada.Size = new System.Drawing.Size(214, 37);
            this.lb_clavePrivada.TabIndex = 5;
            this.lb_clavePrivada.Text = "Clave privada:";
            // 
            // rtb_MensajeEncriptado
            // 
            this.rtb_MensajeEncriptado.Location = new System.Drawing.Point(12, 98);
            this.rtb_MensajeEncriptado.Name = "rtb_MensajeEncriptado";
            this.rtb_MensajeEncriptado.Size = new System.Drawing.Size(1064, 318);
            this.rtb_MensajeEncriptado.TabIndex = 4;
            this.rtb_MensajeEncriptado.Text = "";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.Color.Transparent;
            this.label3.Font = new System.Drawing.Font("Microsoft YaHei UI", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.label3.Location = new System.Drawing.Point(28, 33);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(302, 37);
            this.label3.TabIndex = 1;
            this.label3.Text = "Mensaje encriptado:";
            // 
            // pa_desencriptar
            // 
            this.pa_desencriptar.BackgroundImage = global::tp.Properties.Resources.Fondo_azul;
            this.pa_desencriptar.Controls.Add(this.lb_rutaDesencriptar);
            this.pa_desencriptar.Controls.Add(this.bt_SeleccionarDesencriptarArchivo);
            this.pa_desencriptar.Controls.Add(this.bt_regresardesencriptar);
            this.pa_desencriptar.Controls.Add(this.label8);
            this.pa_desencriptar.Controls.Add(this.label6);
            this.pa_desencriptar.Controls.Add(this.bt_desencrip);
            this.pa_desencriptar.Controls.Add(this.tb_n);
            this.pa_desencriptar.Controls.Add(this.tb_d);
            this.pa_desencriptar.Controls.Add(this.label5);
            this.pa_desencriptar.Controls.Add(this.rtb_desencriptar);
            this.pa_desencriptar.Controls.Add(this.label4);
            this.pa_desencriptar.Location = new System.Drawing.Point(0, 0);
            this.pa_desencriptar.Name = "pa_desencriptar";
            this.pa_desencriptar.Size = new System.Drawing.Size(1103, 531);
            this.pa_desencriptar.TabIndex = 15;
            this.pa_desencriptar.Visible = false;
            // 
            // lb_rutaDesencriptar
            // 
            this.lb_rutaDesencriptar.AutoSize = true;
            this.lb_rutaDesencriptar.BackColor = System.Drawing.Color.Transparent;
            this.lb_rutaDesencriptar.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lb_rutaDesencriptar.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.lb_rutaDesencriptar.Location = new System.Drawing.Point(628, 33);
            this.lb_rutaDesencriptar.Name = "lb_rutaDesencriptar";
            this.lb_rutaDesencriptar.Size = new System.Drawing.Size(0, 20);
            this.lb_rutaDesencriptar.TabIndex = 14;
            // 
            // bt_SeleccionarDesencriptarArchivo
            // 
            this.bt_SeleccionarDesencriptarArchivo.Location = new System.Drawing.Point(432, 23);
            this.bt_SeleccionarDesencriptarArchivo.Name = "bt_SeleccionarDesencriptarArchivo";
            this.bt_SeleccionarDesencriptarArchivo.Size = new System.Drawing.Size(190, 42);
            this.bt_SeleccionarDesencriptarArchivo.TabIndex = 13;
            this.bt_SeleccionarDesencriptarArchivo.Text = "Seleccionar archivo";
            this.bt_SeleccionarDesencriptarArchivo.UseVisualStyleBackColor = true;
            this.bt_SeleccionarDesencriptarArchivo.Click += new System.EventHandler(this.bt_SeleccionarDesencriptarArchivo_Click);
            // 
            // bt_regresardesencriptar
            // 
            this.bt_regresardesencriptar.Location = new System.Drawing.Point(864, 441);
            this.bt_regresardesencriptar.Name = "bt_regresardesencriptar";
            this.bt_regresardesencriptar.Size = new System.Drawing.Size(202, 51);
            this.bt_regresardesencriptar.TabIndex = 11;
            this.bt_regresardesencriptar.Text = "Regresar";
            this.bt_regresardesencriptar.UseVisualStyleBackColor = true;
            this.bt_regresardesencriptar.Click += new System.EventHandler(this.bt_regresardesencriptar_Click);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.BackColor = System.Drawing.Color.Transparent;
            this.label8.Font = new System.Drawing.Font("Microsoft YaHei UI", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.label8.Location = new System.Drawing.Point(684, 422);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(28, 37);
            this.label8.TabIndex = 10;
            this.label8.Text = ")";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.BackColor = System.Drawing.Color.Transparent;
            this.label6.Font = new System.Drawing.Font("Microsoft YaHei UI", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.label6.Location = new System.Drawing.Point(543, 422);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(25, 37);
            this.label6.TabIndex = 9;
            this.label6.Text = ",";
            // 
            // bt_desencrip
            // 
            this.bt_desencrip.Location = new System.Drawing.Point(437, 472);
            this.bt_desencrip.Name = "bt_desencrip";
            this.bt_desencrip.Size = new System.Drawing.Size(275, 49);
            this.bt_desencrip.TabIndex = 8;
            this.bt_desencrip.Text = "Desencriptar";
            this.bt_desencrip.UseVisualStyleBackColor = true;
            this.bt_desencrip.Click += new System.EventHandler(this.bt_desencrip_Click);
            // 
            // tb_n
            // 
            this.tb_n.Location = new System.Drawing.Point(433, 433);
            this.tb_n.Name = "tb_n";
            this.tb_n.Size = new System.Drawing.Size(100, 22);
            this.tb_n.TabIndex = 7;
            // 
            // tb_d
            // 
            this.tb_d.Location = new System.Drawing.Point(574, 433);
            this.tb_d.Name = "tb_d";
            this.tb_d.Size = new System.Drawing.Size(100, 22);
            this.tb_d.TabIndex = 6;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.BackColor = System.Drawing.Color.Transparent;
            this.label5.Font = new System.Drawing.Font("Microsoft YaHei UI", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.label5.Location = new System.Drawing.Point(23, 422);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(372, 37);
            this.label5.TabIndex = 5;
            this.label5.Text = "Ingrese la clave privada: (";
            // 
            // rtb_desencriptar
            // 
            this.rtb_desencriptar.Location = new System.Drawing.Point(12, 80);
            this.rtb_desencriptar.Name = "rtb_desencriptar";
            this.rtb_desencriptar.Size = new System.Drawing.Size(1064, 318);
            this.rtb_desencriptar.TabIndex = 4;
            this.rtb_desencriptar.Text = "";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.BackColor = System.Drawing.Color.Transparent;
            this.label4.Font = new System.Drawing.Font("Microsoft YaHei UI", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.label4.Location = new System.Drawing.Point(12, 20);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(397, 37);
            this.label4.TabIndex = 1;
            this.label4.Text = "Mensaje para desencriptar:";
            // 
            // pa_MensajeDesencriptado
            // 
            this.pa_MensajeDesencriptado.BackgroundImage = global::tp.Properties.Resources.Fondo_azul;
            this.pa_MensajeDesencriptado.Controls.Add(this.bt_descargardescriptado);
            this.pa_MensajeDesencriptado.Controls.Add(this.button1);
            this.pa_MensajeDesencriptado.Controls.Add(this.rtb_MensajeDesencriptado);
            this.pa_MensajeDesencriptado.Controls.Add(this.label7);
            this.pa_MensajeDesencriptado.Location = new System.Drawing.Point(0, 0);
            this.pa_MensajeDesencriptado.Name = "pa_MensajeDesencriptado";
            this.pa_MensajeDesencriptado.Size = new System.Drawing.Size(1103, 531);
            this.pa_MensajeDesencriptado.TabIndex = 16;
            this.pa_MensajeDesencriptado.Visible = false;
            // 
            // bt_descargardescriptado
            // 
            this.bt_descargardescriptado.Location = new System.Drawing.Point(399, 459);
            this.bt_descargardescriptado.Name = "bt_descargardescriptado";
            this.bt_descargardescriptado.Size = new System.Drawing.Size(283, 59);
            this.bt_descargardescriptado.TabIndex = 13;
            this.bt_descargardescriptado.Text = "Descargar archivo";
            this.bt_descargardescriptado.UseVisualStyleBackColor = true;
            this.bt_descargardescriptado.Click += new System.EventHandler(this.bt_descargardescriptado_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(823, 12);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(202, 51);
            this.button1.TabIndex = 12;
            this.button1.Text = "Regresar";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // rtb_MensajeDesencriptado
            // 
            this.rtb_MensajeDesencriptado.Location = new System.Drawing.Point(12, 80);
            this.rtb_MensajeDesencriptado.Name = "rtb_MensajeDesencriptado";
            this.rtb_MensajeDesencriptado.Size = new System.Drawing.Size(1064, 362);
            this.rtb_MensajeDesencriptado.TabIndex = 4;
            this.rtb_MensajeDesencriptado.Text = "";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.BackColor = System.Drawing.Color.Transparent;
            this.label7.Font = new System.Drawing.Font("Microsoft YaHei UI", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.label7.Location = new System.Drawing.Point(12, 20);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(351, 37);
            this.label7.TabIndex = 1;
            this.label7.Text = "Mensaje desencriptado:";
            // 
            // saveFileDialog2
            // 
            this.saveFileDialog2.FileName = "Archivo desencriptado";
            this.saveFileDialog2.Filter = "Archivos de texto (*.txt)|*.txt";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1095, 530);
            this.Controls.Add(this.pa_TextoEncriptado);
            this.Controls.Add(this.pa_desencriptar);
            this.Controls.Add(this.pa_MensajeDesencriptado);
            this.Controls.Add(this.pa_Portada);
            this.Controls.Add(this.pa_Encriptar);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Encriptación RSA";
            this.pa_Portada.ResumeLayout(false);
            this.pa_Portada.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.pa_Encriptar.ResumeLayout(false);
            this.pa_Encriptar.PerformLayout();
            this.pa_TextoEncriptado.ResumeLayout(false);
            this.pa_TextoEncriptado.PerformLayout();
            this.pa_desencriptar.ResumeLayout(false);
            this.pa_desencriptar.PerformLayout();
            this.pa_MensajeDesencriptado.ResumeLayout(false);
            this.pa_MensajeDesencriptado.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel pa_Portada;
        private System.Windows.Forms.PictureBox pictureBox2;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button bt_Desencriptar;
        private System.Windows.Forms.Button bt_Encriptar;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel pa_Encriptar;
        private System.Windows.Forms.Button bt_regresarPortada;
        private System.Windows.Forms.Button bt_EncriptarMensaje;
        private System.Windows.Forms.RichTextBox rtb_mensajeEncriptar;
        private System.Windows.Forms.Label lb_rutaEncriptar;
        private System.Windows.Forms.Button bt_SeleccionarArchivoEncriptar;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
        private System.Windows.Forms.Panel pa_TextoEncriptado;
        private System.Windows.Forms.Button bt_DescargarEncriptado;
        private System.Windows.Forms.Button bt_regresar;
        private System.Windows.Forms.Label lb_clavePrivada;
        private System.Windows.Forms.RichTextBox rtb_MensajeEncriptado;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Panel pa_desencriptar;
        private System.Windows.Forms.Label lb_rutaDesencriptar;
        private System.Windows.Forms.Button bt_SeleccionarDesencriptarArchivo;
        private System.Windows.Forms.Button bt_regresardesencriptar;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Button bt_desencrip;
        private System.Windows.Forms.TextBox tb_n;
        private System.Windows.Forms.TextBox tb_d;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.RichTextBox rtb_desencriptar;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Panel pa_MensajeDesencriptado;
        private System.Windows.Forms.Button bt_descargardescriptado;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.RichTextBox rtb_MensajeDesencriptado;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.SaveFileDialog saveFileDialog2;
        private System.Windows.Forms.Button bt_EnviarCorreo;
    }
}

