create database MakroDB
use MakroDB

CREATE TABLE EMPLEADO
(Cid_empleado int check (Cid_empleado >= 1 and Cid_empleado <= 100000) not null,
Dnombre_empleado char(25) not null,
Dapellido_empleado char(25) not null,
Ffecnac_empleado date not null check(year(Ffecnac_empleado) >= 1921),
Msueldo_empleado real check (Msueldo_empleado >= 900 and Msueldo_empleado <= 5000) not null,
Ddireccion_empleado char(100),
primary key(Cid_empleado)
)

CREATE TABLE TIENDA
(Cid_tienda int check (Cid_tienda >= 1 and Cid_tienda <= 1000) not null,
Ddepartamento_tienda char(25) not null,
Dciudad_tienda char(25) not null,
Ddistrito_tienda char(25) not null,
Dcalle_tienda char(100) not null,
Naforo_tienda int check (Naforo_tienda >= 1000 and Naforo_tienda <= 10000) not null,
primary key(Cid_tienda)
)

CREATE TABLE TIENDA_EMPLEADO
(Cid_tienda int check (Cid_tienda >= 1 and Cid_tienda <= 1000) not null,
Cid_empleado int check (Cid_empleado >= 1 and Cid_empleado <= 100000) not null,
primary key clustered(Cid_tienda, Cid_empleado),
foreign key (Cid_tienda) references TIENDA (Cid_tienda),
foreign key (Cid_empleado) references EMPLEADO (Cid_empleado)
)

CREATE TABLE DEPARTAMENTO
(Cid_departamento int check (Cid_departamento >= 1 and Cid_departamento <= 100) not null,
Dnombre_departamento char(25) not null,
Mpresupuesto_departamento real check (Mpresupuesto_departamento >= 5000 and Mpresupuesto_departamento <= 100000) not null,
Ffecha_departamento date not null check(year(Ffecha_departamento) >= 1921),
primary key(Cid_departamento)
)

CREATE TABLE EMPLEADO_DEPARTAMENTO
(Cid_departamento int check (Cid_departamento >= 1 and Cid_departamento <= 100) not null,
Cid_empleado int check (Cid_empleado >= 1 and Cid_empleado <= 100000) not null,
primary key clustered(Cid_departamento, Cid_empleado),
foreign key (Cid_departamento) references DEPARTAMENTO (Cid_departamento),
foreign key (Cid_empleado) references EMPLEADO (Cid_empleado)
)

CREATE TABLE ALMACEN
(Cid_almacen int check (Cid_almacen >= 1 and Cid_almacen <= 1000) not null,
Ddireccion_almacen char(50) not null,
primary key (Cid_almacen)
)

CREATE TABLE EMPLEADO_ALMACEN
(Cid_empleado int check (Cid_empleado >= 1 and Cid_empleado <= 100000) not null,
Cid_almacen int check (Cid_almacen >= 1 and Cid_almacen <= 1000) not null,
primary key clustered(Cid_almacen, Cid_empleado),
foreign key (Cid_almacen) references ALMACEN (Cid_almacen),
foreign key (Cid_empleado) references EMPLEADO (Cid_empleado)
)

CREATE TABLE PRODUCTO
(Cid_producto int check (Cid_producto >= 1 and Cid_producto <= 100000) not null,
Dnombre_producto char(50) not null,
Ddescripcion_producto char(100),
Mprecio_producto real check (Mprecio_producto >= 0 and Mprecio_producto <= 100000) not null,
primary key (Cid_producto)
)

CREATE TABLE ALMACEN_PRODUCTO
(Cid_almacen int check (Cid_almacen >= 1 and Cid_almacen <= 1000) not null,
Cid_producto int check (Cid_producto >= 1 and Cid_producto <= 100000) not null,
Ncantidad_AlmPro int check (Ncantidad_AlmPro >= 0 and Ncantidad_AlmPro <= 10000) not null
primary key clustered(Cid_almacen, Cid_producto),
foreign key (Cid_almacen) references ALMACEN (Cid_almacen),
foreign key (Cid_producto) references PRODUCTO (Cid_producto)
)

CREATE TABLE PROVEEDOR
(Cid_proveedor int check (Cid_proveedor >= 1 and Cid_proveedor <= 10000) not null,
Dnombre_proveedor char(50) not null,
Cruc_proveedor bigint check (Cruc_proveedor >= 100000000000 and Cruc_proveedor <= 999999999999) not null,
primary key (Cid_proveedor)
)

CREATE TABLE COMPRA
(Cid_compra int check (Cid_compra >= 1 and Cid_compra <= 1000000) not null,
Cid_proveedor int check (Cid_proveedor >= 1 and Cid_proveedor <= 10000) not null,
Cid_empleado int check (Cid_empleado >= 1 and Cid_empleado <= 100000) not null,
Mimporte_compra real check (Mimporte_compra >= 0 and Mimporte_compra <= 100000) not null,
Ffecha_compra date check(year(Ffecha_compra) >= 2000) not null,
primary key (Cid_compra),
foreign key (Cid_proveedor) references PROVEEDOR (Cid_proveedor),
foreign key (Cid_empleado) references EMPLEADO (Cid_empleado)
)

CREATE TABLE DETALLECOMPRA
(Cid_compra int check (Cid_compra >= 1 and Cid_compra <= 1000000) not null,
Cid_producto int check (Cid_producto >= 1 and Cid_producto <= 100000) not null,
Ncantidad_DetCom int check (Ncantidad_DetCom >= 0 and Ncantidad_DetCom > 100000) not null,
Msubtotal_DetCom real check (Msubtotal_DetCom >= 0 and Msubtotal_DetCom > 1000000) not null,
primary key clustered(Cid_compra, Cid_producto),
foreign key (Cid_compra) references COMPRA (Cid_compra),
foreign key (Cid_producto) references PRODUCTO (Cid_producto)
)

CREATE TABLE CATALOGO
(Cid_catalogo int check (Cid_catalogo >= 1 and Cid_catalogo <= 10000) not null,
Ffecini_catalogo date check(year(Ffecini_catalogo) >= 2000) not null, 
Ffecfin_catalogo date check(year(Ffecfin_catalogo) >= 2000) not null,
primary key (Cid_catalogo)
)

CREATE TABLE CATALOGO_PRODUCTO
(Cid_catalogo int check (Cid_catalogo >= 1 and Cid_catalogo <= 10000) not null,
Cid_producto int check (Cid_producto >= 1 and Cid_producto <= 100000) not null,
primary key clustered(Cid_catalogo, Cid_producto),
foreign key (Cid_catalogo) references CATALOGO (Cid_catalogo),
foreign key (Cid_producto) references PRODUCTO (Cid_producto)
)

CREATE TABLE CATEGORIA
(Cid_categoria int check (Cid_categoria >= 1 and Cid_categoria <= 1000) not null,
Dnombre_categoria char(50) not null,
Ddescripcion_categoria char(100),
primary key (Cid_categoria)
)

CREATE TABLE CATEGORIA_PRODUCTO
(Cid_categoria int check (Cid_categoria >= 1 and Cid_categoria <= 1000) not null,
Cid_producto int check (Cid_producto >= 1 and Cid_producto <= 100000) not null,
primary key clustered(Cid_categoria, Cid_producto),
foreign key (Cid_categoria) references CATEGORIA (Cid_categoria),
foreign key (Cid_producto) references PRODUCTO (Cid_producto)
)

CREATE TABLE OFERTA
(Cid_oferta int check (Cid_oferta >= 1 and Cid_oferta <= 100000) not null,
Dnombre_oferta char(50) not null,
Ddescripcion_oferta char(100),
Drequisitos_oferta char(500) not null,
Ffecini_oferta date check(year(Ffecini_oferta) >= 2000) not null, 
Ffecfin_oferta date check(year(Ffecfin_oferta) >= 2000) not null,
primary key (Cid_oferta)
)

CREATE TABLE PRODUCTO_OFERTA
(Cid_oferta int check (Cid_oferta >= 1 and Cid_oferta <= 100000) not null,
Cid_producto int check (Cid_producto >= 1 and Cid_producto <= 100000) not null,
Pdescuento_OfePro real check (Pdescuento_OfePro >= 0 and Pdescuento_OfePro <= 100) not null,
Mprecio_OfePro real check (Mprecio_OfePro >= 0 and Mprecio_OfePro <= 100000) not null,
primary key clustered(Cid_oferta, Cid_producto),
foreign key (Cid_oferta) references OFERTA (Cid_oferta),
foreign key (Cid_producto) references PRODUCTO (Cid_producto)
)

CREATE TABLE MARCA
(Cid_marca int check (Cid_marca >= 1 and Cid_marca <= 10000) not null,
Dnombre_marca char(50) not null,
Ddescripcion_marca char(100),
Dslogan_marca char(100) not null,
Cruc_marca bigint check (Cruc_marca >= 100000000000 and Cruc_marca <= 999999999999) not null,
primary key (Cid_marca)
)

CREATE TABLE MARCA_PRODUCTO
(Cid_marca int check (Cid_marca >= 1 and Cid_marca <= 10000) not null,
Cid_producto int check (Cid_producto >= 1 and Cid_producto <= 100000) not null,
primary key clustered(Cid_marca, Cid_producto),
foreign key (Cid_marca) references MARCA (Cid_marca),
foreign key (Cid_producto) references PRODUCTO (Cid_producto)
)

CREATE TABLE CLIENTE
(Cid_cliente int check (Cid_cliente >= 1 and Cid_cliente <= 1000000) not null,
Dnombre_cliente char(25) not null,
Dapellido_cliente char(25) not null,
Ffecnac_cliente date check(year(Ffecnac_cliente) >= 1921),
Ddireccion_cliente char(100),
Cdni_cliente real check (Cdni_cliente >= 10000000 and Cdni_cliente <= 99999999) not null,
primary key(Cid_cliente)
)

CREATE TABLE VENTA
(Cid_venta int check (Cid_venta >= 1 and Cid_venta <= 1000000) not null,
Cid_tienda int check (Cid_tienda >= 1 and Cid_tienda <= 1000) not null,
Cid_empleado int check (Cid_empleado >= 1 and Cid_empleado <= 100000) not null,
Cid_cliente int check (Cid_cliente >= 1 and Cid_cliente <= 1000000) not null,
Mimporte_venta real check (Mimporte_venta >= 0 and Mimporte_venta <= 100000) not null,
Ffecha_venta date check(year(Ffecha_venta) >= 2000) not null,
primary key (Cid_venta),
foreign key (Cid_tienda) references TIENDA (Cid_tienda),
foreign key (Cid_empleado) references EMPLEADO (Cid_empleado),
foreign key (Cid_cliente) references CLIENTE (Cid_cliente)
)

CREATE TABLE DETALLEVENTA
(Cid_venta int check (Cid_venta >= 1 and Cid_venta <= 1000000) not null,
Cid_producto int check (Cid_producto >= 1 and Cid_producto <= 100000) not null,
Ncantidad_DetVen int check (Ncantidad_DetVen >= 0 and Ncantidad_DetVen > 100000) not null,
Msubtotal_DetVen real check (Msubtotal_DetVen >= 0 and Msubtotal_DetVen > 1000000) not null,
primary key clustered(Cid_venta, Cid_producto),
foreign key (Cid_venta) references VENTA (Cid_venta),
foreign key (Cid_producto) references PRODUCTO (Cid_producto)
)

CREATE TABLE MEDIOPAGO
(Cid_mediopago int check (Cid_mediopago >= 1 and Cid_mediopago <= 20) not null,
Dtipo_mediopago char(50) not null,
Cruc_mediopago bigint check (Cruc_mediopago >= 100000000000 and Cruc_mediopago <= 999999999999),
primary key(Cid_mediopago)
)

CREATE TABLE COMPROBANTE
(Cid_venta int check (Cid_venta >= 1 and Cid_venta <= 1000000) not null,
Cid_mediopago int check (Cid_mediopago >= 1 and Cid_mediopago <= 20) not null,
Nnum_comprobante int check (Nnum_comprobante >= 1 and Nnum_comprobante <= 1000000) not null unique,
Ncuotas_comprobante int check(Ncuotas_comprobante >= 0 and Ncuotas_comprobante <= 50) not null,
Bboleta_comprobante bit not null,
Bfactura_comprobante bit not null,
primary key clustered(Cid_venta, Cid_mediopago),
foreign key (Cid_venta) references VENTA (Cid_venta),
foreign key (Cid_mediopago) references MEDIOPAGO (Cid_mediopago)
)

use MakroDB

INSERT INTO EMPLEADO
VALUES
('1', 'Benedicto', 'Serbin', '1983-05-19', '3664', 'Av. 15 de Julio Mz. A Lt. 39 Zona A (Huaycan)'),
('2', 'Frascuelo', 'Dominguez', '1963-04-27', '1237', 'Vía de Evitamiento Mz. G Lote 24 Urb Los Parques de Monterrico'),
('3', 'Stefano', 'Peron', '1988-09-22', '1698', 'Av. Nicolas Ayllon 5351 – Manzana C Lote 9 -10 – Urbanización Porvenir'),
('4', 'Leon', 'Olguin', '1998-05-26', '4695', 'Carretera Central Km 3 1/2'),
('5', 'Nataniel', 'Nevarez', '1974-06-08', '2729', 'Av. Nicolas Ayllon Sector B Lote 4'),
('6', 'Elia', 'Renta', '1983-12-10', '4375', 'Carretera Central Km 6 Mz-M Lt-2a'),
('7', 'Aurelius', 'Verdugo', '1979-02-10', '2579', 'Av. Circulnvalación 2769'),
('8', 'Jeronimo', 'Tello', '1955-07-20', '3630', 'Av. Carretera Central Esq. Av.La Estrella, Km 10.5'),
('9', 'Gabrio', 'Rodriquez', '1971-12-08', '4078', 'Av. Los Incas 205 Mz. A Lt. 7 Ex. Av. Circunvalacion - Ate'),
('10', 'Domenico', 'Vayo', '1977-01-02', '2687', 'Av. La Molina Cdra. 3'),
('11', 'Horado', 'Jacinto', '1961-01-30', '2978', 'Av. Carretera Central 5580 (Int. 4 Mz. M Lote 1 - Pre Urbania Barbadillo)'),
('12', 'Leopoldo', 'Lobato', '1991-06-18', '4836', 'Av. Elmer Faucett Nº 720 - Carmen de la Legua Reynoso'),
('13', 'Normando', 'Polanco', '1980-12-09', '3095', 'Av. Saenz Peña 416 Callao'),
('14', 'Ernesto', 'Escalona', '1984-06-20', '3237', 'Av. Oscar Benavides 5185'),
('15', 'Donzel', 'Barajas', '2001-09-07', '2513', 'AV TOMAS VALLE S/N MZ R1 LY 01'),
('16', 'Ambrosio', 'Rodriquez', '1979-09-30', '2809', 'AV. SAENZ PEÑA 1250'),
('17', 'Fanuco', 'Bustos', '1971-07-19', '2519', 'AV OSCAR R. BENAVIDES 4921'),
('18', 'Delmar', 'Florez', '1962-09-09', '1079', 'AV COLONIAL 3866'),
('19', 'Videl', 'Brion', '1954-09-30', '3388', 'AV ARGENTINA 3093'),
('20', 'Orlando', 'Galicia', '1953-12-18', '2064', 'AV COLONIAL 4161'),
('21', 'Raymon', 'Revilla', '1971-01-05', '4908', 'AV CANTA CALLAOS/N URB SAN JUAN'),
('22', 'Tajo', 'Lujan', '1963-12-02', '2591', 'CARRETERA CANTA CALLAO 378'),
('23', 'Farruco', 'Alejandre', '1990-04-25', '3930', 'AV LIMA 4208'),
('24', 'Salbatore', 'Cendejas', '1966-06-11', '2412', 'AV. SAENZ PEÑA 471'),
('25', 'Hernan', 'Pando', '1974-05-08', '3588', 'Av. Argentina No. 3093, Local 174, Calle 2, Pabellón 1, Callao'),
('26', 'Paz', 'Cancel', '1960-01-10', '3257', 'COMAS Av. Túpac Amaru Nº 7841, Mz C, Lote 10 – Urbanización San Juan Bautista 1era. Etapa'),
('27', 'Roberto', 'Sandoval', '1987-04-15', '1161', 'Av. Túpac Amaru 6518 - Mz D Lt 15 - Urb. La Pascana'),
('28', 'Patrido', 'Roa', '1992-05-19', '1137', 'Av.2 Lado Norte Mz EX Lote 8 Urb. El Retablo –Comas (Belaunde 846)'),
('29', 'Xalbador', 'Arias', '1976-03-08', '3948', 'AV. TUPAC AMARU 3900'),
('30', 'Reynaldo', 'Granados', '1986-06-14', '4456', 'AV. UNIVERSITARIA, LT 1, MZ E, URB. EL RETABLO II'),
('31', 'Amado', 'Salaz', '1969-10-06', '4894', 'AV. TUPAC AMARU 3860'),
('32', 'Segundo', 'Roa', '1994-10-20', '1281', 'AV. TÚPAC AMARU 3900'),
('33', 'Roque', 'Dario', '1958-07-07', '4589', 'Av. Belaunde 265 (esquina con Tupac Amaru) - Urb. Huaquillay II Etapa'),
('34', 'Gaspard', 'Tejera', '1968-04-09', '4172', 'Jirón Ancash 2151'),
('35', 'Tobias', 'Valera', '1953-11-12', '3479', 'Ca. Ancash 2479'),
('36', 'Noe', 'Cordova', '1968-01-14', '3878', 'Av. Carlos Alberto Izaguirre Sub Lote 1A Mz B (Av. Gerardo Unger 3807)'),
('37', 'Jerardo', 'Saiz', '1998-08-23', '3332', 'Av. Pacifico 579'),
('38', 'Reyes', 'Duque', '1957-05-24', '1916', 'Av. Alfredo Mendiola 3900'),
('39', 'Blas', 'Custodio', '1968-05-11', '2528', 'Av. Tomas Valle Esquina Con Panamericana Norte C.C. Plaza Norte'),
('40', 'Donato', 'Sotomayor', '1960-04-05', '3744', 'Av. Tomas Valle 1400 (Cruce Con Panamericana Norte) - C.C. Plaza Lima Norte'),
('41', 'Huberto', 'Canizales', '1953-06-28', '3082', 'Av. Alfredo Mendiola N° 3698, Valle De La Piedra Liza, Independencia'),
('42', 'Amado', 'Paul', '1988-06-10', '4035', 'Av. Alfredo Mendiola 1400'),
('43', 'Felippe', 'Benitez', '1980-04-11', '1340', 'Esq. Av. Carlos Eyzaguirre Con Panamericana Norte'),
('44', 'Jesus', 'Betances', '1973-09-01', '2356', 'Av. Alfredo Mendiola 3698 A-01 Fnd. Muleria'),
('45', 'Frederico', 'Guiterrez', '1976-07-02', '3817', 'Av. Alfredo Mendiola 1400.'),
('46', 'Fresco', 'Milan', '1993-12-03', '3341', 'Av. Industrial 3515-3517 Int. A 09'),
('47', 'Bonifacio', 'Martinez', '1962-03-13', '2926', 'Av. Alfredo Mendiola 1400.'),
('48', 'Rodolfo', 'Cerrito', '1969-03-08', '2949', 'Av. Industrial 3515'),
('49', 'Mannie', 'Guitron', '1972-01-01', '3902', 'Av. Santiago De Surco Esq. Con Ca Iván Huerta Y Av. Andrés Tinoco Mz. B3 Lote 01'),
('50', 'Dante', 'Can', '2000-08-25', '4257', 'Av. Alfredo Mendiola 3698, Independencia - CC. Mega Plaza'),
('51', 'Hermosa', 'Ballesteros', '1991-10-02', '1597', 'Av. Republica Dominicana 505'),
('52', 'Alfreda', 'De Mora', '1992-04-14', '1511', 'Av. Brasil 3339'),
('53', 'Marina', 'Ciervo', '1987-08-11', '1560', 'Av. General Garzon 1337'),
('54', 'Puebla', 'Crespo', '1971-05-30', '2017', 'Av. Alfonso Ugarte 273- 299'),
('55', 'Levina', 'Calle', '1995-10-26', '4837', 'Conjunto Residencial San Felipe, Edificio 67-C, 1er. Piso'),
('56', 'Purisima', 'Polanco', '1982-04-18', '2128', 'Av. Brasil 1599'),
('57', 'Elbertina', 'Beas', '1995-07-14', '3783', 'AV. SANTA ROSA CDRA. 347 LT.1'),
('58', 'Lore', 'Espiritu', '1954-07-30', '3881', 'Jr. Manuel Segura 277'),
('59', 'Estefany', 'Frisco', '1977-11-24', '3435', 'Av. Abancay 974'),
('60', 'Estebana', 'Vallez', '1968-09-03', '4130', 'Av. Oscar R. Benavides 707 (Ex Colonial)'),
('61', 'Itsaso', 'Asencio', '1999-05-19', '1402', 'Av. Oscar R. Benavides 3002 '),
('62', 'Dolorita', 'Coito', '1963-01-22', '2730', 'Jr. Cuzco 245 - 255'),
('63', 'Pura', 'Mascorro', '1967-11-06', '1047', 'Av. Proceres De La Independencia 1632'),
('64', 'Albertine', 'Luna', '1995-05-22', '4974', 'Esq. Av. Wilson Con Av. España'),
('65', 'Rosemarie', 'Grijalva', '1988-06-24', '3407', 'Esq. Jirón De La Unión Con Jirón Huancavelica'),
('66', 'Salvadora', 'Morga', '1986-11-23', '4249', 'Alm. Alfonso Ugarte Esq. Con Av. Del Progreso'),
('67', 'Rosalind', 'Balasco', '1993-07-07', '1663', 'Esq. Av. Wilson Con Av. España'),
('68', 'Verdad', 'Siles', '1963-11-29', '3425', 'Cruce Jr. de la Unión con Jr. Huancavelica'),
('69', 'Olivia', 'Parra', '1980-10-03', '1732', 'Jr. De La Union 630'),
('70', 'Xevera', 'Vine', '1965-05-26', '3921', 'Av. Garcilaso de la Vega 1337, Cercado de Lima, 1, Perú (Espaldas del Hotel Sheraton)'),
('71', 'Florencia', 'Beas', '1969-07-10', '3821', 'Av. Tacna 640'),
('72', 'Lucita', 'Zamora', '1966-06-18', '1801', 'Av. Tacna 665'),
('73', 'Alejandra', 'Alvidrez', '1951-10-14', '3090', 'Av. Naciones Unidas 1003'),
('74', 'Adoracion', 'Ortis', '1979-08-16', '2791', 'Av. Paseo de La República 144, tienda 6.'),
('75', 'Ceria', 'Jose', '1954-12-23', '4246', 'Av. Abancay 457 (frente a Biblioteca Nacional)'),
('76', 'Alondra', 'Vasconcellos', '1996-11-13', '4283', 'Jr. de la Unión 811'),
('77', 'Eloisa', 'Gato', '1988-06-29', '4261', 'Av. Arenales 1520'),
('78', 'Jovina', 'Vida', '1988-10-07', '2081', 'Av. Arenales 736'),
('79', 'Presentacion', 'Rivera', '1973-11-18', '4602', 'Av. Abancay 974'),
('80', 'Ceri', 'Palomares', '1983-02-19', '3422', 'Av. Republica Dominicana 505'),
('81', 'Morissa', 'Jara', '1986-07-28', '1195', 'Av. Ignacio Merino 1921'),
('82', 'Xalbadora', 'Iglesias', '1993-05-27', '2502', 'Av. Arenales 2380'),
('83', 'Rufina', 'Alvillar', '2002-03-10', '4929', 'Av. Arequipa 2230'),
('84', 'Hortencia', 'Villarreal', '1987-05-26', '4253', 'Av. Carlos Izaguirre 524'),
('85', 'Savannah', 'Cendejas', '1960-04-16', '2939', 'Av. Antúnez de Mayolo 1001-A, Urbanización Mercurio'),
('86', 'Araceli', 'Florez', '1961-02-16', '1729', 'Av. Alfredo Mendiola 3539 (Esquina Panamericana con Carlos Alberto Izaguirre)'),
('87', 'Dulcinia', 'Estopinal', '1998-03-29', '2726', 'Av. Central MZ 70 Lt 10 - San Elias - Pueblo Joven PVM Confraternidad'),
('88', 'Arama', 'Clemente', '2001-01-17', '2482', 'Av. Angélica Gamarra 759 - Mz. D lote N° 7 - Urb. El Trébol'),
('89', 'Zanita', 'Pelaez', '1985-08-25', '4937', 'Av. Las Palmeras 3854 (Izaguirre con Antunez de Mayolo)'),
('90', 'Dominica', 'Lastra', '1952-12-24', '1979', 'Esq. Av. Antunez De Mayolo Cdra. 9 Con Calle Orion'),
('91', 'Carolina', 'Nepomuceno', '1965-10-26', '2348', 'Camal Garay Mz A I Lote 4'),
('92', 'Josefa', 'Carrasco', '1967-09-19', '3620', 'Av. Alfredo Mendiola 5810'),
('93', 'Corazana', 'Peguero', '1999-10-04', '1844', 'Av. Alfredo Mendiola 3698 (C.C. Megaplaza)'),
('94', 'Carmina', 'Baile', '1967-01-14', '3131', 'Av. Prolongación Tomás Valle 499-H, Local 13, San Martín de Porres'),
('95', 'Aintzane', 'Rossel', '1967-11-12', '2263', 'Av. Alfredo Mendiola 3771-A'),
('96', 'Aintzane', 'Ballesteros', '1973-11-01', '2981', 'Av. Prolongación Tomás Valle 499-H, Local 13, San Martín de Porres'),
('97', 'Belinda', 'Rengifo', '1996-02-20', '4451', 'Av. Alfredo Mendiola 3771-A'),
('98', 'Yadra', 'Vidales', '1961-01-02', '4927', 'Av. Puente Piedra Sur No. 162 - Urbanización Santo Domingo Mz. C - Lote 12 – 2do. Piso'),
('99', 'Alise', 'Villalobos', '1994-01-06', '3635', 'CALLE SAN LORENZO MZ. A LOTE 01B'),
('100', 'Cristine', 'Guerrero', '1998-01-05', '4164', 'AV. PUENTE PIEDRA SUR 443')

INSERT INTO TIENDA
VALUES
('1', 'Lima', 'Lima', 'Independencia', 'C.C. Plaza Norte, Av. Tomas Valle con Panamericana Norte', '5000'),
('2', 'Lima', 'Callao', 'Callao', 'Av. Elmer Faucett (entre la Av. Colonial y Av. Argentina )', '6000'),
('3', 'Lima', 'Lima', 'Santa Anita', 'Carretera Central # 345 Km 1 - ( a 1 cdra.del óvalo Santa Anita )', '4500'),
('4', 'Lima', 'Lima', 'Surco', 'Av. Jorge Chávez N°1218', '4000'),
('5', 'Arequipa', 'Arquipa', 'José Luis Bustamante y River', 'Av. Andrés Avelino Cáceres S/N', '7000'),
('6', 'Lambayeque', 'Chiclayo', 'Chiclayo', 'Av. Jorge Basadre #299 Urb. Campodónico', '3000'),
('7', 'Lima', 'Lima', 'San Juan de Lurigancho', 'Av. Gran Pajatén Cruce con Jr. Santuario', '5500'),
('8', 'La Libertad', 'Trujillo', 'Trujillo', 'Av. Nicolas de Pierola con Av. Micaela Bastidas', '6500'),
('9', 'Piura', 'Piura', 'Piura', 'Av. Prolongación Sanchez Cerro S/N', '6200'),
('10', 'Lima', 'Lima', 'Comas', 'Av. Chacra Cerro S/N Lote 115', '4800'),
('11', 'Lima', 'Lima', 'Villa El Salvador', 'Cruce Panamericana Sur con Av. Mateo Pumacahua', '7200'),
('12', 'Junin', 'Huancayo', 'Huancayo', 'Av. Prolongación José Carlos Mariategui S/N', '7100'),
('13', 'Ica', 'Chincha', 'Grocio Prado', 'Carretera Panamericana Sur Km. 195', '6900'),
('14', 'Ica', 'Ica', 'Ica', 'Av. Nicolás de Rivero el Viejo 1117', '5300'),
('15', 'Lima', 'Huaura', 'Huacho', 'Av. Panamericana cruce con Av. San Martin', '5200'),
('16', 'La Libertad', 'Trujillo', 'Trujillo', 'Av. Industrial cruce con Av. Federico Villareal', '3500')