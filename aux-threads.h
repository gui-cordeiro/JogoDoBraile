/*
 * -> Código-Fonte do Jogo do Braile
 * -> Desenvolvido por: Guilherme Cordeiro
 * -> Ano: 2017, 2024
 */

DWORD WINAPI e1(LPVOID params) {
    int contador = 0;
    cleanScreen(6, false);

    while(contador < 4){
        //linhaCol(37, 2); printf("%d", contador);
        linhaCol(11, 3); printf("       ,lllllllllc:,.           ");
        linhaCol(12, 3); printf("       ,0MMMMMMMMMWNKd,         ");
        linhaCol(13, 3); printf("       .dWMNxcllllllool'        ");
        linhaCol(14, 3); printf("        oWMK;'xOOOOOkxdoc,..    ");
        linhaCol(15, 3); printf("     ...oWMK;;0XXXXXNWWMMWX0xl,.");
        linhaCol(16, 3); printf("   .oKx'oWMK; ......';codk0NMWO,");
        linhaCol(17, 3); printf("  :0WWx'oWMK,        ;kko,.,dx' ");
        linhaCol(18, 3); printf(" :XMWk'.oWMK,       ;0MM0'      ");
        linhaCol(19, 3); printf(".kMM0'  oWMXo'''',ckNMWO,       ");
        linhaCol(20, 3); printf("'0MWx.  oWMMWNNNNWMMNOl.        ");
        linhaCol(21, 3); printf(".kMM0,  oWMW0xk0XWMNx.          ");
        linhaCol(22, 3); printf(" ;KMWO;.cKWX;  .'xNMNd.         ");
        linhaCol(23, 3); printf("  ;0WMXxc:ll.    .lXMWk'  .;xk, ");
        linhaCol(24, 3); printf("   .l0WMWKkoc;''...cKMW0;.dNMWO'");
        linhaCol(25, 3); printf("     .;dOXWMMWNNNXO;;0WMKc;odc' ");
        linhaCol(26, 3); printf("        'cllodxkkkkl.'kWMXl.    ");
        linhaCol(27, 3); printf("      .oX0d'         .dNMNd.    ");
        linhaCol(28, 3); printf("      ;0WWNd.         .lXWWOc.  ");
        linhaCol(29, 3); printf("      '::::;.           ':::;.  ");

        textColor(LIGHTRED, _BLACK);
        linhaCol(11, 36); printf("            ########################            ");
        linhaCol(12, 36); printf("              ####################              ");
        linhaCol(13, 36); printf("                ################                ");
        linhaCol(14, 36); printf("                 ##############                 ");
        linhaCol(15, 36); printf("#                  ##########                  #");
        linhaCol(16, 36); printf("####                ########                ####");
        linhaCol(17, 36); printf("########             ######             ########");
        linhaCol(18, 36); printf("#############        ######        #############");
        linhaCol(19, 36); printf("################################################");
        linhaCol(20, 36); printf("################################################");
        linhaCol(21, 36); printf("################################################");
        linhaCol(22, 36); printf("############         ######         ############");
        linhaCol(23, 36); printf("#######              ######             ########");
        linhaCol(24, 36); printf("####                ########                ####");
        linhaCol(25, 36); printf("#                  ##########                  #");
        linhaCol(26, 36); printf("                 ##############                 ");
        linhaCol(27, 36); printf("                ################                ");
        linhaCol(28, 36); printf("              ####################              ");
        linhaCol(29, 36); printf("            ########################            ");
        textColor(WHITE, _BLACK);

        linhaCol(11, 85); printf(" ......                    ...... ");
        linhaCol(12, 85); printf(".:OXX0:                    lKXKk, ");
        linhaCol(13, 85); printf("  lNMWd.                  .OMMK;  ");
        linhaCol(14, 85); printf("  .oNMNl.  .';::ccc::;,'..'lxk:   ");
        linhaCol(15, 85); printf("   .xWMXc.oKNWWMMMMMWWWNX0kdl:.   ");
        linhaCol(16, 85); printf("    'kWMK:;xkxolllllodxk0XNWMWKx' ");
        linhaCol(17, 85); printf("  .:;;0MM0,            ,ccccdKXd. ");
        linhaCol(18, 85); printf(" .xW0;:KMWk.          ,0WNd. .'   ");
        linhaCol(19, 85); printf(".dWMX: cXMWx.         :dxo'       ");
        linhaCol(20, 85); printf("'0MMk.  lNMNo..cllllloooooolllll, ");
        linhaCol(21, 85); printf(".OMMk.  .dWMXc.dNMMMMMMMMMMMMMMWd.");
        linhaCol(22, 85); printf(" oNMNo.  .kWMK:.;:cllllc::::dXMWd.");
        linhaCol(23, 85); printf(" .dNMNk;. 'OWM0, .:kOk:     ,KMWd.");
        linhaCol(24, 85); printf("  .:0WMNOo';0MWOdxKMWk'..':oOWMWd.");
        linhaCol(25, 85); printf("    .:kXWMO;:KMMWWMM0;:OXNWMWXOo' ");
        linhaCol(26, 85); printf("       .:oxc.lNMMMMK:,kK0kdl;..   ");
        linhaCol(27, 85); printf("             .oNMMXc ....         ");
        linhaCol(28, 85); printf("              .xXKo.              ");
        linhaCol(29, 85); printf("               .;'.               ");

        while(mudar == false) {
            if (mudar == true) {
                Sleep(1500);
                break;
            }
        }
        mudar = false;
        cleanScreen(6, false);

        linhaCol(10, 2); printf(" .d8888b.  888          888             888            8888888b.                            888                                ");
        linhaCol(11, 2); printf("d88P  Y88b 888          888             888            888   Y88b                           888                                ");
        linhaCol(12, 2); printf("888    888 888          888             888            888    888                           888                                ");
        linhaCol(13, 2); printf("888        888 888  888 88888b.     .d88888  .d88b.    888   d88P .d88b.   .d88b.   8888b.  888888  8888b.  .d8888b            ");
        linhaCol(14, 2); printf("888        888 888  888 888 \"88b   d88\" 888 d8P  Y8b   8888888P\" d8P  Y8b d88P\"88b     \"88b 888        \"88b 88K          ");
        linhaCol(15, 2); printf("888    888 888 888  888 888  888   888  888 88888888   888 T88b  88888888 888  888 .d888888 888    .d888888 \"Y8888b.          ");
        linhaCol(16, 2); printf("Y88b  d88P 888 Y88b 888 888 d88P   Y88b 888 Y8b.       888  T88b Y8b.     Y88b 888 888  888 Y88b.  888  888      X88           ");
        linhaCol(17, 2); printf(" \"Y8888P\"  888  \"Y88888 88888P\"     \"Y88888  \"Y8888    888   T88b \"Y8888   \"Y88888 \"Y888888  \"Y888 \"Y888888  88888P'");
        linhaCol(18, 2); printf("                                                                               888                                             ");
        linhaCol(19, 2); printf("                                                                          Y8b d88P                                             ");
        linhaCol(20, 2); printf("                                                                           \"Y88P\"                                            ");

        linhaCol(23, 2); printf("888     888                                             888                .d8888b.                                            ");
        linhaCol(24, 2); printf("888     888                                             888               d88P  Y88b                                           ");
        linhaCol(25, 2); printf("888     888                                             888               888    888                                           ");
        linhaCol(26, 2); printf("Y88b   d88P 8888b.  .d8888b   .d8888b .d88b.        .d88888  8888b.       888         8888b.  88888b.d88b.   8888b.            ");
        linhaCol(27, 2); printf(" Y88b d88P     \"88b 88K      d88P\"   d88\"\"88b      d88\" 888     \"88b      888  88888     \"88b 888 \"888 \"88b     \"88b ");
        linhaCol(28, 2); printf("  Y88o88P  .d888888 \"Y8888b. 888     888  888      888  888 .d888888      888    888 .d888888 888  888  888 .d888888          ");
        linhaCol(29, 2); printf("   Y888P   888  888      X88 Y88b.   Y88..88P      Y88b 888 888  888      Y88b  d88P 888  888 888  888  888 888  888           ");
        linhaCol(30, 2); printf("    Y8P    \"Y888888  88888P'  \"Y8888P \"Y88P\"        \"Y88888 \"Y888888       \"Y8888P88 \"Y888888 888  888  888 \"Y888888  ");

        while(mudar == false) {
            if (mudar == true) {
                Sleep(1500);
                break;
            }
        }
        mudar = false;
        cleanScreen(6, false);

        int linha = 9;
        int col = 9;
        setlocale(LC_ALL, "C");
        SetConsoleOutputCP(CP_UTF8);
        for (int lin = linha; lin <= 31; lin ++) {
            linhaCol(lin, col);
            printf("\u2591\u2592\u2593");
            for (int control = 0; control <= 30; control ++) {
                printf("\u2588");
            }
            printf("\u2593\u2592\u2591");
            col += 3;
        }
        textColor(_WHITE, LIGHTRED);
        linhaCol(17, 56); printf("\u2588\u2588\u2588\u2588\u2588\u2588");
        linhaCol(18, 57); printf("\u2588\u2588\u2588\u2588");
        linhaCol(19, 53); printf("\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588");
        linhaCol(20, 53); printf("\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588");
        linhaCol(21, 57); printf("\u2588\u2588\u2588\u2588");
        linhaCol(22, 56); printf("\u2588\u2588\u2588\u2588\u2588\u2588");

        linhaCol(18, 53); printf("\u2588\u2588");
        linhaCol(18, 63); printf("\u2588\u2588");
        linhaCol(21, 53); printf("\u2588\u2588");
        linhaCol(21, 63); printf("\u2588\u2588");

        textColor(_BLACK, BROWN);
        linhaCol(10, 96); printf("*    *    *    *");
        linhaCol(12, 96); printf("*    *    *    *");

        textColor(_BLACK, WHITE);
        SetConsoleOutputCP(850);
        setlocale(LC_ALL, "Portuguese");

        while(mudar == false) {
            if (mudar == true) {
                Sleep(1500);
                break;
            }
        }
        mudar = false;
        cleanScreen(6, false);

        linhaCol(11, 14); printf(" .d88888b.        .d8888b.  8888888 .d8888b.         d8888 888b    888 88888888888 8888888888 ");
        linhaCol(12, 14); printf("d88P\" \"Y88b      d88P  Y88b   888  d88P  Y88b       d88888 8888b   888     888     888        ");
        linhaCol(13, 14); printf("888     888      888    888   888  888    888      d88P888 88888b  888     888     888        ");
        linhaCol(14, 14); printf("888     888      888          888  888            d88P 888 888Y88b 888     888     8888888    ");
        linhaCol(15, 14); printf("888     888      888  88888   888  888  88888    d88P  888 888 Y88b888     888     888        ");
        linhaCol(16, 14); printf("888     888      888    888   888  888    888   d88P   888 888  Y88888     888     888        ");
        linhaCol(17, 14); printf("Y88b. .d88P      Y88b  d88P   888  Y88b  d88P  d8888888888 888   Y8888     888     888        ");
        linhaCol(18, 14); printf(" \"Y88888P\"        \"Y8888P88 8888888 \"Y8888P88 d88P     888 888    Y888     888     8888888888");
        linhaCol(22, 14); printf("8888888b.        d8888       .d8888b.   .d88888b.  888      8888888 888b    888        d8888");
        linhaCol(23, 14); printf("888  \"Y88b      d88888      d88P  Y88b d88P\" \"Y88b 888        888   8888b   888       d88888");
        linhaCol(24, 14); printf("888    888     d88P888      888    888 888     888 888        888   88888b  888      d88P888");
        linhaCol(25, 14); printf("888    888    d88P 888      888        888     888 888        888   888Y88b 888     d88P 888");
        linhaCol(26, 14); printf("888    888   d88P  888      888        888     888 888        888   888 Y88b888    d88P  888");
        linhaCol(27, 14); printf("888    888  d88P   888      888    888 888     888 888        888   888  Y88888   d88P   888");
        linhaCol(28, 14); printf("888  .d88P d8888888888      Y88b  d88P Y88b. .d88P 888        888   888   Y8888  d8888888888");
        linhaCol(29, 14); printf("8888888P\" d88P     888       \"Y8888P\"   \"Y88888P\"  88888888 8888888 888    Y888 d88P     888");

        while(mudar == false) {
            if (mudar == true) {
                Sleep(1500);
                break;
            }
        }
        mudar = false;
        cleanScreen(6, false);

        linhaCol(16, 23); printf("       d8888 8888888b.  8888888888 888b    888        d8888  .d8888b.  888   ");
        linhaCol(17, 23); printf("      d88888 888   Y88b 888        8888b   888       d88888 d88P  Y88b 888   ");
        linhaCol(18, 23); printf("     d88P888 888    888 888        88888b  888      d88P888 Y88b.      888   ");
        linhaCol(19, 23); printf("    d88P 888 888   d88P 8888888    888Y88b 888     d88P 888  \"Y888b.   888  ");
        linhaCol(20, 23); printf("   d88P  888 8888888P\"  888        888 Y88b888    d88P  888     \"Y88b. 888 ");
        linhaCol(21, 23); printf("  d88P   888 888        888        888  Y88888   d88P   888       \"888 Y8P  ");
        linhaCol(22, 23); printf(" d8888888888 888        888        888   Y8888  d8888888888 Y88b  d88P  \"   ");
        linhaCol(23, 23); printf("d88P     888 888        8888888888 888    Y888 d88P     888  \"Y8888P\"  888 ");

        while(mudar == false) {
            if (mudar == true) {
                Sleep(1500);
                break;
            }
        }
        mudar = false;
        cleanScreen(6, false);


        contador ++;
    }

    box(9, 1, 31, 119);

    linhaCol(10, 3); printf(" _____         _              _____              _        _____                      _        _____               ");
    linhaCol(11, 3); printf("|   __|___ ___| |_ ___ ___   |   __|___ ___    _| |___   |  |  |___ ___ ___ ___    _| |___   |   __|___ _____ ___ ");
    linhaCol(12, 3); printf("|   __| .'|_ -|  _| -_|  _|  |   __| . | . |  | . | . |  |  |  | .'|_ -|  _| . |  | . | .'|  |  |  | .'|     | .'|");
    linhaCol(13, 3); printf("|_____|__,|___|_| |___|_|    |_____|_  |_  |  |___|___|   \\___/|__,|___|___|___|  |___|__,|  |_____|__,|_|_|_|__,|");
    linhaCol(14, 3); printf("                                   |___|___|                                                                      ");

    linhaCol(16, 18); printf("Acalme-se, torcedor(a) flamenguista/tricolor/botafoguense ou de qualquer outro time!");

    linhaCol(19, 12); printf("Isso aqui foi uma brincadeira que eu quis adicionar ao Jogo do Braile! Foi bem divertido criá-lo");
    linhaCol(20, 13); printf("pois o Vasco da Gama sempre foi muito importante para a minha vida. Por fim, dedico esta minha");
    linhaCol(21, 15); printf("singela homenagem do Gigante da Colina ao meu pai, um grande vascaíno que me ensinou a ser");
    linhaCol(22, 33); printf("apaixonado pelo Legítimo Clube do Povo desde criança!");

    linhaCol(25, 3); printf("Espero que tenha gostado, e claro, respeito em primeiro lugar! Pressione Enter para continuar com o Jogo do Braile.");

    textColor(_BLACK, LIGHTRED);
    box(28, 5, 30, 115);
    linhaCol(29, 7); printf("O hino do Vasco em 8 bits foi criado pelo canal \"Clubes em 8-Bits\" no YouTube: https://youtu.be/tehFoER2e2E");
    textColor(_BLACK, WHITE);

    return 0;
}

DWORD WINAPI letra(LPVOID params){
    setlocale(LC_ALL, "Portuguese");

    Sleep(3000); //18180
    mudar = true;
    Sleep(3250);
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("                . . .                 ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(3000);
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("                . . .                 ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(3000);
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("                . . .                 ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(3000);
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("                . . .                 ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(2700);
    textColor(_BLACK, BROWN);

    linhaCol(37, 41); printf("    Vamos todos cantar de coração     ");
    textColor(_BLACK, WHITE);
    Sleep(3700); //18100
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("    A Cruz de Malta é o meu pendão    ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(3820); //21920
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf(" Tu tens o nome do heroico português  ");
    textColor(_BLACK, WHITE);
    Sleep(3740); //25660
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("Vasco da Gama, a tua fama assim se fez");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(3980); //29640
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("    Tua imensa torcida é bem feliz    ");
    textColor(_BLACK, WHITE);
    Sleep(3750); //33390
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("  Norte-Sul, Norte-Sul deste Brasil   ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(3730); //37120
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("   Tua estrela, na terra a brilhar    ");
    textColor(_BLACK, WHITE);
    Sleep(3600); //40720
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("            Ilumina o mar             ");
    textColor(_BLACK, WHITE);
    mudar = true;


    Sleep(3750); //44470
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("                . . .                 ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(2700);
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("                . . .                 ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(2650);
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("                . . .                 ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(2650);
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("                . . .                 ");
    textColor(_BLACK, WHITE);
    mudar = true;

    Sleep(3050);//56130
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("      No atletismo, és um braço       ");
    textColor(_BLACK, WHITE);
    Sleep(3500); //59630
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("         No remo, és imortal          ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(3750); //63380
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("       No futebol, és um traço        ");
    textColor(_BLACK, WHITE);
    Sleep(3270); //66650
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("      De união Brasil-Portugal!       ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(4500); //71130
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("      No atletismo, és um braço       ");
    textColor(_BLACK, WHITE);
    Sleep(3500); //59630
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("         No remo, és imortal          ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(3750); //63380
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("       No futebol, és um traço        ");
    textColor(_BLACK, WHITE);
    Sleep(3270); //66650
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("      De união Brasil-Portugal!       ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(3970); //86190
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("                . . .                 ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(3950); //94080
    mudar = true;
    Sleep(3890); //94080
    mudar = true;
    Sleep(1000); //94080
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("                VASCO!                ");
    textColor(_BLACK, WHITE);
    Sleep(2000); //94080
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf(" Criado com carinho pelo vascaíno Gui ");
    textColor(_BLACK, WHITE);


    setlocale(LC_ALL, "C");
    return 0;
}

DWORD WINAPI nicetry(LPVOID params) {
    int contador = 0;
    cleanScreen(6, false);

    while(contador < 4){
        //linhaCol(37, 2); printf("%d", contador);
        for (int cont = 0; cont <= 4; cont ++) {
            if (cont % 2 == 0 && mudar != true) {
                linhaCol(9, 31); printf("  ?GPY~               :77777777777777!!!!!!!777777!!!. ");
                linhaCol(10, 31); printf("  JG5Y^               !7777777777777777!!!!!!!777!!!!. ");
                linhaCol(11, 31); printf(" .YG5J^              .777777777777777777!!!!!!!!!!!!!. ");
                linhaCol(12, 31); printf(" .YG5?:               !???????JJJJ???7777!!!!!!!!!!!!!.");
                linhaCol(13, 31); printf(" :5G5?:               ^????????????JJ???777!!!!!!!!!!!.");
                linhaCol(14, 31); printf(" ^PP5?.               :????????????????????7777!!!!!!!!.");
                linhaCol(15, 31); printf(" ~PP57.               .7777??????????????????777!!!!!!~.");
                linhaCol(16, 31); printf(" !PPY!                 ^77777?????????????7777777!!!!!7:");
                linhaCol(17, 31); printf(" 7PPY!                  77777777777777777777777777!!77Y~");
                linhaCol(18, 31); printf(" 7PPY!                 ^?77777777!!77777777777777777JP57");
                linhaCol(19, 31); printf(" ?PPJ~              .!5B#PY?7777!!!777777777777777?5GGP7");
                linhaCol(20, 31); printf(".JPPJ~           .!JGB######G5?77!!!7777777777?J5GBBBGP!");
                linhaCol(21, 31); printf(".JP5J^         :75GBB########BG5PPPPPP5555PPB#######BGP7");
                linhaCol(22, 31); printf(".JP5?:       ^JPP55PGGBBB###BBGPPB####BBB#&&&####BBBBBG7");
                linhaCol(23, 31); printf(".JP57:     .?5P55555GGGBBBBBBGBBPBBBBGB#&&#B#&&###BG5?~ ");
                linhaCol(24, 31); printf(":YPY7.    ~5P5555PPGGBBBBBGBBPGBBBBGG#B57~:.:7J?7~:.    ");
                linhaCol(25, 31); printf(":YPY!.   ?BBBBBBBBBBBBBBBGPGBGBBBBBBP7.                 ");
                linhaCol(26, 31); printf("^5PJ7.  ~BB#&&&#BGPPGGGBBBBBBBBBBBGJ.                   ");
                linhaCol(27, 31); printf("^YPJ!   YB#####BGGGGBBB####BBBGPY7^                     ");
                linhaCol(28, 31); printf("~Y5?!   !JJY5PGGPPPPGPPPP5Y?7~^.                        ");
                linhaCol(29, 31); printf("~JJ?~         ...:::::...                               ");
                linhaCol(30, 31); printf("~??7^                                                   ");
                linhaCol(31, 31); printf("!??7^                                                   ");
            } else {
                 linhaCol(9, 31); printf("  ?GPY~        ~JJJJJJJJJJJYJJ???77777?777777???~       ");
                linhaCol(10, 31); printf("  JG5Y^         ^JJJJJJJJJJJJJJJJ??7777???????7775^     ");
                linhaCol(11, 31); printf(" .YG5J^          :JJJJJJJJJJJJJJJJJ???7?????J??7Y#B!    ");
                linhaCol(12, 31); printf(" .YG5?:           JJJJJJJJJJJJJJJJJ?????????JJ??B&##7   ");
                linhaCol(13, 31); printf(" :5G5?:           :JJJJJJJJJJJJJJJJ??J?????JJ??5&&&&#?  ");
                linhaCol(14, 31); printf(" ^PP5?.            ?JJJJJJJJJJJJJJ??JJJJJJJ????B&&&&&#? ");
                linhaCol(15, 31); printf(" ~PP57.            7JJJJJJJJJJJJJJJJ?????????YG&&&&&&#B~");
                linhaCol(16, 31); printf(" !PPY!             7JJJJJJJJJ?????????????J5B#&########B");
                linhaCol(17, 31); printf(" 7PPY!             ^JJJJJJJJJJJJ??????JY5GB###&&&&&&&&##");
                linhaCol(18, 31); printf(" 7PPY!             .P5YJJJJJJJJJY5PGB######&&&&&&&&&&&&#");
                linhaCol(19, 31); printf(" ?PPJ~             Y&&#&#######&&&@@&&###&&&&&&&&&&&&B?.");
                linhaCol(20, 31); printf(".JPPJ~            Y&&&&@@@@@@@&&&&&&&###&@@&&&&&&&G?:   ");
                linhaCol(21, 31); printf(".JP5J^          .P&&&&&&&&&&&&&@&&&####&&G~..::^:.      ");
                linhaCol(22, 31); printf(".JP5?:         7B&&&&&&@@@&&&&&@&&&B#&&#!               ");
                linhaCol(23, 31); printf(".JP57:       7P#####&&&&&&@@&&&&&&&###G.                ");
                linhaCol(24, 31); printf(":YPY7.     :5GGGGBB#&&&&&&&&&&&&&####P.                 ");
                linhaCol(25, 31); printf(":YPY!.    ?BBGGB###&&&&&&&#####&&&##P.                  ");
                linhaCol(26, 31); printf("^5PJ7.  .G&&&&&&&##BB######&&&&&&&B?                    ");
                linhaCol(27, 31); printf("^YPJ!   G#&&&&&##BBB####&&###BGPJ^                      ");
                linhaCol(28, 31); printf("~Y5?!   G&&&&&&&####BBGP5J7~:.                          ");
                linhaCol(29, 31); printf("~JJ?~   ~JJJJ?7!~~^:..                                  ");
                linhaCol(30, 31); printf("~??7^                                                   ");
                linhaCol(31, 31); printf("!??7^                                                   ");
            }
            Sleep(300);
        }

        while(mudar == false) {
            if (mudar == true) {
                Sleep(100);
                break;
            }
        }
        mudar = false;
        cleanScreen(6, false);
        linhaCol(10, 11); printf("888b    888                                          .d8888b.                                     ");
        linhaCol(11, 11); printf("8888b   888                                         d88P  Y88b                                    ");
        linhaCol(12, 11); printf("88888b  888                                         888    888                                    ");
        linhaCol(13, 11); printf("888Y88b 888  .d88b.  888  888  .d88b.  888d888      888         .d88b.  88888b.  88888b.   8888b. ");
        linhaCol(14, 11); printf("888 Y88b888 d8P  Y8b 888  888 d8P  Y8b 888P\"        888  88888 d88\"\"88b 888 \"88b 888 \"88b     \"88b\"");
        linhaCol(15, 11); printf("888  Y88888 88888888 Y88  88P 88888888 888          888    888 888  888 888  888 888  888 .d888888");
        linhaCol(16, 11); printf("888   Y8888 Y8b.      Y8bd8P  Y8b.     888          Y88b  d88P Y88..88P 888  888 888  888 888  888");
        linhaCol(17, 11); printf("888    Y888  \"Y8888    Y88P    \"Y8888  888           \"Y8888P88  \"Y88P\"  888  888 888  888 \"Y888888\"");



        linhaCol(20, 11); printf("       .d8888b.  d8b                        Y88b   d88P                     888     888           ");
        linhaCol(21, 11); printf("      d88P  Y88b Y8P                         Y88b d88P                      888     888           ");
        linhaCol(22, 11); printf("      888    888                              Y88o88P                       888     888           ");
        linhaCol(23, 11); printf("      888        888 888  888  .d88b.          Y888P  .d88b.  888  888      888     888 88888b.   ");
        linhaCol(24, 11); printf("      888  88888 888 888  888 d8P  Y8b          888  d88\"\"88b 888  888      888     888 888 \"88b  ");
        linhaCol(25, 11); printf("      888    888 888 Y88  88P 88888888          888  888  888 888  888      888     888 888  888  ");
        linhaCol(26, 11); printf("      Y88b  d88P 888  Y8bd8P  Y8b.              888  Y88..88P Y88b 888      Y88b. .d88P 888 d88P  ");
        linhaCol(27, 11); printf("       \"Y8888P88 888   Y88P    \"Y8888           888   \"Y88P\"   \"Y88888       \"Y88888P\"  88888P\"   ");
        linhaCol(28, 11); printf("                                                                                        888       ");
        linhaCol(29, 11); printf("                                                                                        888       ");
        linhaCol(30, 11); printf("                                                                                        888       ");

        while(mudar == false) {
            if (mudar == true) {
                Sleep(100);
                break;
            }
        }
        mudar = false;
        cleanScreen(6, false);


        linhaCol(9, 6); printf("                                                    :^^^:.                                                   ");
        linhaCol(10, 6); printf("                                                 .7PGGGP5Y~                                                  ");
        linhaCol(11, 6); printf("                                                 J#BGGP5J?7.                                                 ");
        linhaCol(12, 6); printf("                                                .PBGGGGGYJY^                                                 ");
        linhaCol(13, 6); printf("                                                .5GPPPPP5??^                                                 ");
        linhaCol(14, 6); printf("                                                 ^PGGGGP5?7.                                                 ");
        linhaCol(15, 6); printf("                                                 :JGGGGGPJ~                                                  ");
        linhaCol(16, 6); printf("                                       .::^^~!!7?Y?5GBBBP7!~^^::...                                          ");
        linhaCol(17, 6); printf("                            .....:::^~!7?????J??YY?JPGBBY!J?!777!!!~^::.                                     ");
        linhaCol(18, 6); printf("                   ::..:^^~~~~~!~!!!!!7?JYYJJ???PY??JGG5J?PY77??JJJ??77!~^^:^^^^:..                          ");
        linhaCol(19, 6); printf(" !JJ?7~^:.    .:^~!~~~~~~~~!!!!!!!!!!7?JJYYYYJJYPJ???Y5JJJ5Y??J555YJJJJJJ????????7!~^:...                    ");
        linhaCol(20, 6); printf("~PGGPPPP5YJ??JY5PPPJ7~~!!!!!!!~~^~~^:..... :JYY5PJJ???JJJJ55JJYY?:::^~~!?JJJJJJ?????77!~~~:.                 ");
        linhaCol(21, 6); printf("^^!PBG5Y55J????7!~:!J!!!~~~^::.             :YY5PYYYJ??JJJ5PYJ?!.         .^~7?JJJJJ???JPGG5Y?~::.           ");
        linhaCol(22, 6); printf("  ~PGPY5PY:.       .77:.                     ^YPG55JJJJYYJ5P?7!^               .:^~???!~!!7?JY5555JY?7?7777^ ");
        linhaCol(23, 6); printf(" :?5Y7!JJ~           .                       .J5G5YJJJJYYYPP7~^.                    ..        .^!77?7!~~7PP! ");
        linhaCol(24, 6); printf(".!JJ?7~?J~.                                   7YPYYYYYYYJ?Y5!~^.                                        ?BB! ");
        linhaCol(25, 6); printf(":!???7~!~~!~^::.:^!7!~^:::::::::...          ~GGGGP555Y5Y?Y5J?~.                                       !5GG7 ");
        linhaCol(26, 6); printf("~!YJY?~~^^^7?JJYPGGGGGGGGBBBBBBBGGPP5YJ?7??JYB######BBPGGGBGGPY?!^::.                                .7YY55?.");
        linhaCol(27, 6); printf("^JGGPY7~~~~!7?JPBBBBBBB#############BBBBGGBB###########BBBBBBBBBBBBGPPPP5555YJ??7!!!!^         ....:!JYJJJYJ.");
        linhaCol(28, 6); printf(":5BGGGY??????Y555PB####&&&&&#####BBBBBBBBBBGGGBB##B##################################BP555PY??777???JJYYYYJJ:");
        linhaCol(29, 6); printf(".^~^~~~^^^:::..   :^^~!7?JY5PGBBBB#####BBBBBBBBBBB####################################&&&&#PYJ???????YPPPPYY.");
        linhaCol(30, 6); printf("                             ..:^^~!77?JYYY5PGB###&&&&&&&&&&&&&&&############&&&&##########G5YYYYYYY5PBBBG5Y.");
        linhaCol(31, 6); printf("                                            .:^^~!!!7777??????77!!!!!~~~~^^^~!!77!7!!!!!!!777???JJJJY5PPP5Y?.");


        while(mudar == false) {
            if (mudar == true) {
                Sleep(100);
                break;
            }
        }
        mudar = false;
        cleanScreen(6, false);

        textColor(DARKGRAY, _BLACK);
        for (int cont = 0; cont <= 4; cont ++) {
            if (cont % 2 == 0 && mudar != true) {
                linhaCol(9, 1); printf("                                                       .^G#BP~                                 ");
                linhaCol(10, 1); printf("                                          ..:^!7J55GBBB###BY!:                                ");
                linhaCol(11, 1); printf("                                  ^?5GB#&&&&&#G5J7!^:.                                        ");
                linhaCol(12, 1); printf("                                 :@@@@@@@#!.                                                  ");
                linhaCol(13, 1); printf("                               ?G&@@@@@@@@&Y                              ..:..               ");
                linhaCol(14, 1); printf("                               B@@@@@@@@@@@@B~                      ^5B##&&@@@&P.             ");
                linhaCol(15, 1); printf("                                Y@@@@@@@@@@@@@&7               7PB#&@@@@@@@@@@@@&7            ");
                linhaCol(16, 1); printf("                                 B@@@@@@@@@@@@@@B^         :!5&@@@@@@@@@@@@@@@&B?.            ");
                linhaCol(17, 1); printf("                            .:75B&@@@@@@@@@@@@@@@@&PJ7J5G#&@@@@@@@@@@@@@&GY7~:.               ");
                linhaCol(18, 1); printf("  ........             .^?P&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&BPJ!~^~!^.                     ");
                linhaCol(19, 1); printf("&@@@@@@@@@@&&&&#BBGPG#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&P7^.                            ... ");
                linhaCol(20, 1); printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&.                         .^YG#&&@@&Y");
                linhaCol(21, 1); printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J                      :JB&@@@&&BG5!.");
                linhaCol(22, 1); printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&Y.                 ~B@@@&Y^..      ");
                linhaCol(23, 1); printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@P^             !#@@@&J           ");
                linhaCol(24, 1); printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&G7.     .!P&@@@@5.            ");
                linhaCol(25, 1); printf("?Y555PGB@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&@@@@@@@@@@@@@@@@@@@G^:?B@@@@@@G:              ");
                linhaCol(26, 1); printf("       !@@@@@@@@@@@@@@@@@@@@@@@@@@&#PY7~^:..    ^5&@@@@@@@@@@@@@@@@@@@@@@@@&Y.                ");
                linhaCol(27, 1); printf("      Y@@@@@@@@@@@@@@@@@@@@@@@@G~.                 :?B&@@@@@@@@@@@@@@@@@@&?.                  ");
                linhaCol(28, 1); printf("    :#@@@@@@@@@@@@@@@@@@@@@@#7.                        :!J5Y?~:.^7YGBBPJ^                     ");
                linhaCol(29, 1); printf("   Y@@@@@@@@@@@@@@@@@@@@@@B^                                                                  ");
                linhaCol(30, 1); printf(" ~&@@@@@@@@@@@@@@@@@@@@@B~                                                                    ");
                linhaCol(31, 1); printf("#@@@@@@@@@@@@@@@@@@@@&Y:                                                                      ");
            } else {
                linhaCol(9, 1); printf("                                                                                              ");
                linhaCol(10, 1); printf("                                                                                              ");
                linhaCol(11, 1); printf("                                                                                              ");
                linhaCol(12, 1); printf("                                                                                              ");
                linhaCol(13, 1); printf("                                                                            ...               ");
                linhaCol(14, 1); printf("                                                                     .:!5G#&&&&#!             ");
                linhaCol(15, 1); printf("                                             .^!??JJJJJJ5PPGGGGGGP5P#&@@@@@@@@@@@&BB#&&#G5!   ");
                linhaCol(16, 1); printf("                                        .^JG&&@@@@@@@@@&####&@@@@@@@@@@@@@@@@@@@@@&BY!^.      ");
                linhaCol(17, 1); printf("                                     .!B@@@@@@@@@@@@@@P  .^?G@@@@@@@@@@@@@@@@#P7:.            ");
                linhaCol(18, 1); printf("                               .:~?5#@@@@@@@@@@@@@@@@@&B#&@@@@@@@@@&&@@@@@&?.                 ");
                linhaCol(19, 1); printf("                       .:~?5B#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&G?^:~G&@@&?                    ");
                linhaCol(20, 1); printf(" PBPGBBBB##BBBBBGPPGB&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&?: .!P#@@@&J                      ");
                linhaCol(21, 1); printf(" &@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@!^Y#@@@@@&J.                       ");
                linhaCol(22, 1); printf(".&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&J.                         ");
                linhaCol(23, 1); printf(".&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@B7                            ");
                linhaCol(24, 1); printf(".@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@?.                              ");
                linhaCol(25, 1); printf(".@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&G7.                                ");
                linhaCol(26, 1); printf(".@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&B5?7!~~^~~~^:.                                     ");
                linhaCol(27, 1); printf(" 5@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&#5!.                                                    ");
                linhaCol(28, 1); printf(" ^@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&B5!:                                                         ");
                linhaCol(29, 1); printf(" #@@@@@@@@@@@@@@@@@@@@@@@@&#P?^.                                                              ");
                linhaCol(30, 1); printf(".&@@@@@@@@@@@@@@@@@@@@@G~.                                                                    ");
                linhaCol(31, 1); printf(".&@@@@@@@@@@@@@@@@&BY~.                                                                       ");
            }
            Sleep(250);
        }
        textColor(WHITE, _BLACK);

        while(mudar == false) {
            if (mudar == true) {
                Sleep(100);
                break;
            }
        }
        mudar = false;
        cleanScreen(6, false);


        contador ++;
    }
    box(9, 1, 31, 119);

    linhaCol(10, 14); printf("                                                                                         __ ");
    linhaCol(11, 14); printf(" _____       _          _           __                             _____                |  |");
    linhaCol(12, 14); printf("|     |___ _| |___    _| |___    __|  |___ ___ ___    ___ _____   | __  |___ ___ _ _ ___|  |");
    linhaCol(13, 14); printf("| | | | . | . | . |  | . | -_|  |  |  | . | . | . |  | -_|     |  | __ -|  _| -_| | | -_|__|");
    linhaCol(14, 14); printf("|_|_|_|___|___|___|  |___|___|  |_____|___|_  |___|  |___|_|_|_|  |_____|_| |___|\\_/|___|__|");
    linhaCol(15, 56); printf("|___|");

    linhaCol(19, 54); printf("No momento, este modo está sendo ");
    textColor(_BLACK, DARKGRAY);
    printf("desenvolvido");
    textColor(_BLACK, WHITE);
    printf(".");
    linhaCol(20, 42); printf("Verifique o repositório no GitHub e veja se há uma ");
    textColor(_BLACK, LIGHTGREEN);
    printf("atualização do jogo");
    textColor(_BLACK, WHITE);
    printf(".");

    textColor(_BLACK, BROWN);
    linhaCol(23, 46); printf("P.S.: Pedimos desculpas ao Rickroll, leve isso na brincadeira!");
    textColor(_BLACK, LIGHTGREEN);

    textColor(_BLACK, DARKGRAY);
    linhaCol(16, 7); printf("             .7PB#####GY      ");
    linhaCol(17, 7); printf("           ^P&G?^..^G&#?      ");
    linhaCol(18, 7); printf("          Y&G:   .Y&B!     :: ");
    linhaCol(19, 7); printf("         Y&5    7&B^     ~B&&7");
    linhaCol(20, 7); printf("         #&.    J&G.   !B&Y?&#");
    linhaCol(21, 7); printf("        :&&:     ^G&G5#&J. ~&#");
    linhaCol(22, 7); printf("      .Y&B!        .~!^   .#&!");
    linhaCol(23, 7); printf("    :P&B~                !&&! ");
    linhaCol(24, 7); printf("  ^G&G^         .^:::^7P##J.  ");
    linhaCol(25, 7); printf(".G&P:         .J&#GGGG57:     ");
    linhaCol(26, 7); printf("B&7         .5&B!             ");
    linhaCol(27, 7); printf("B&?       :P&B~               ");
    linhaCol(28, 7); printf(".5&G~. .~G&G^                 ");
    linhaCol(29, 7); printf("  :YB###BY:                   ");

    textColor(_BLACK, LIGHTRED);
    box(26, 41, 30, 113);
    linhaCol(27, 43); printf("A música \"Never Gonna Give You Up\" em 8-bits foi gerada pelo programa");
    linhaCol(28, 43); printf("GXSCC e com base no arquivo MIDI criado e disponibilizado pelo canal");
    linhaCol(29, 43); printf("   do YouTube \"The Music Decomposer\": https://youtu.be/r2K1yPbLrWc");
    textColor(_BLACK, WHITE);

    return 0;
}

DWORD WINAPI ricklyrics(LPVOID params){
    setlocale(LC_ALL, "Portuguese");

    Sleep(3000); //18180
    mudar = true;
    Sleep(2500);
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("                . . .                 ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(2500);
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("                . . .                 ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(2500);
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("                . . .                 ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(2500);
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("                . . .                 ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(3050);
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("                . . .                 ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(2500); //18750

    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("      We're no strangers to love      ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(3850); //22600
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("    You know the rules and so do I    ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(4300); //26900
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("       A full commitment's what       ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(1715); //28615
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("           I'm thinking of            ");
    textColor(_BLACK, WHITE);
    Sleep(2585);//31200
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("      You wouldn't get this from      ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(1850); //33050
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("            any other guy             ");
    textColor(_BLACK, WHITE);
    Sleep(2120); //35170
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("I just wanna tell you how I'm feeling ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(2630); //40500
    mudar = true;
    Sleep(2500);
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("      Gotta make you understand       ");
    textColor(_BLACK, WHITE);
    Sleep(2650);//43150
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("       Never gonna give you up        ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(2090); //45240
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("       Never gonna let you down       ");
    textColor(_BLACK, WHITE);
    Sleep(2180);//47420
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("Never gonna run around and desert you ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(1475); //51645
    mudar = true;
    Sleep(2750);
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("       Never gonna make you cry       ");
    textColor(_BLACK, WHITE);
    Sleep(2080);//53725
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("       Never gonna say goodbye        ");
    textColor(_BLACK, WHITE);
    mudar = true;
    Sleep(2255);//55880
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf(" Never gonna tell a lie and hurt you  ");
    textColor(_BLACK, WHITE);
    Sleep(3750);//55880
    textColor(_BLACK, BROWN);
    linhaCol(37, 41); printf("Aguarde! Novo modo em desenvolvimento!");
    textColor(_BLACK, WHITE);
    setlocale(LC_ALL, "C");
    return 0;
}

DWORD WINAPI redes(LPVOID params){
    int linha = 10, coluna = 9;
    textColor(WHITE, _BLACK);
    box(9, coluna - 2, 12, coluna + 56);
    linhaCol(linha, coluna + 1); printf("O código-fonte do jogo está disponível no repositório");
    linhaCol(linha + 1, coluna + 4); printf("\"https://github.com/gui-cordeiro/JogoDoBraile\"");
    linhaCol(linha + 4, coluna); printf("                  @@@@@@@@@@@@@@@@@@@                  ");
    linhaCol(linha + 5, coluna); printf("              @@@@@@@@@@@@@@@@@@@@@@@@@@@              ");
    linhaCol(linha + 6, coluna); printf("           @@@@@@  @@@@@@@@@@@@@@@@@  @@@@@@           ");
    linhaCol(linha + 7, coluna); printf("         @@@@@@@    @@@@@@@@@@@@@@@    @@@@@@@         ");
    linhaCol(linha + 8, coluna); printf("       @@@@@@@@                         @@@@@@@@       ");
    linhaCol(linha + 9, coluna); printf("      @@@@@@@@@                         @@@@@@@@@      ");
    linhaCol(linha + 10, coluna); printf("     @@@@@@@@@                           @@@@@@@@@     ");
    linhaCol(linha + 11, coluna); printf("     @@@@@@@@                             @@@@@@@@     ");
    linhaCol(linha + 12, coluna); printf("     @@@@@@@@                             @@@@@@@@     ");
    linhaCol(linha + 13, coluna); printf("     @@@@@@@@                             @@@@@@@@     ");
    linhaCol(linha + 14, coluna); printf("     @@@@@@@@@                           @@@@@@@@@     ");
    linhaCol(linha + 15, coluna); printf("      @@@@@@@@@@                       @@@@@@@@@@      ");
    linhaCol(linha + 16, coluna); printf("       @@@@   @@@@@@@@           @@@@@@@@@@@@@@@       ");
    linhaCol(linha + 17, coluna); printf("        @@@@@   @@@@@@           @@@@@@@@@@@@@@        ");
    linhaCol(linha + 18, coluna); printf("          @@@@@                  @@@@@@@@@@@@          ");
    linhaCol(linha + 19, coluna); printf("             @@@@@@@@@           @@@@@@@@@             ");
    linhaCol(linha + 20, coluna); printf("                @@@@@@           @@@@@@                ");

    while(1) {
        textColor(LIGHTBLUE, _BLACK);
        box(9, coluna + 68, 12, coluna + 100);
        linhaCol(linha, coluna + 70); printf("Siga as minhas redes sociais!");
        linhaCol(linha + 1, coluna + 72); printf("Twitter/X: @guis_cordeiro");
        linhaCol(linha + 4, coluna + 65); printf("                         ..::.          ");
        linhaCol(linha + 5, coluna + 65); printf("  :.                  ~G&@@@@@@#?..:75^ ");
        linhaCol(linha + 6, coluna + 65); printf(" .@@P:              :&@@@@@@@@@@@@@@&7:.");
        linhaCol(linha + 7, coluna + 65); printf(" ~@@@@#7.          .@@@@@@@@@@@@@@@@&#J ");
        linhaCol(linha + 8, coluna + 65); printf("  @@@@@@@&5~.      ?@@@@@@@@@@@@@@@@?   ");
        linhaCol(linha + 9, coluna + 65); printf("  .&@@@@@@@@@@&BPY?G@@@@@@@@@@@@@@@&    ");
        linhaCol(linha + 10, coluna + 65); printf(" :P?B@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@B    ");
        linhaCol(linha + 11, coluna + 65); printf("  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@~    ");
        linhaCol(linha + 12, coluna + 65); printf("  .B@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@B     ");
        linhaCol(linha + 13, coluna + 65); printf("    ^5&@@@@@@@@@@@@@@@@@@@@@@@@@@&.     ");
        linhaCol(linha + 14, coluna + 65); printf("    .G&@@@@@@@@@@@@@@@@@@@@@@@@@&.      ");
        linhaCol(linha + 15, coluna + 65); printf("     :B@@@@@@@@@@@@@@@@@@@@@@@@P        ");
        linhaCol(linha + 16, coluna + 65); printf("       .!5B&@@@@@@@@@@@@@@@@@#^         ");
        linhaCol(linha + 17, coluna + 65); printf("        .~5&@@@@@@@@@@@@@@@B^           ");
        linhaCol(linha + 18, coluna + 65); printf(".~?YPB#@@@@@@@@@@@@@@@@@B7.             ");
        linhaCol(linha + 19, coluna + 65); printf("  :!5B&@@@@@@@@@@@&#P7:                 ");
        linhaCol(linha + 20, coluna + 65); printf("        ...::::..                       ");
        textColor(WHITE, _BLACK);

        mudarRedes = true;
        Sleep(2000);
        mudarRedes = false;

        box(9, coluna + 68, 12, coluna + 100);
        linhaCol(linha, coluna + 70); printf("Siga as minhas redes sociais!");
        linhaCol(linha + 1, coluna + 72); printf("Twitter/X: @guis_cordeiro");
        linhaCol(linha + 4, coluna + 65); printf("~B@@@@@@@@@@G^                  .J&@G~  ");
        linhaCol(linha + 5, coluna + 65); printf(" .J&@#!^^^~5@@J.              .?#@B!    ");
        linhaCol(linha + 6, coluna + 65); printf("   :P@&?    ~B@B!           .J&@G!      ");
        linhaCol(linha + 7, coluna + 65); printf("     !#@B~    J@@P:       .J&@G~        ");
        linhaCol(linha + 8, coluna + 65); printf("      .J@@5:   :P@&?    :J&@G~          ");
        linhaCol(linha + 9, coluna + 65); printf("        ^P@&?    !#@B~:J&@G~            ");
        linhaCol(linha + 10, coluna + 65); printf("          !#@B~   .J@@&@P~              ");
        linhaCol(linha + 11, coluna + 65); printf("           .J@@5.   ^P@@?               ");
        linhaCol(linha + 12, coluna + 65); printf("             ^P@&7    !#@B~             ");
        linhaCol(linha + 13, coluna + 65); printf("              ^#@@G^   .Y@@Y.           ");
        linhaCol(linha + 14, coluna + 65); printf("            ^5@@5Y@@Y.   ^G@&7          ");
        linhaCol(linha + 15, coluna + 65); printf("          ^5@@5^  ^G@#7    7&@G^        ");
        linhaCol(linha + 16, coluna + 65); printf("        ^P@@5:      7&@G^   .Y@@Y.      ");
        linhaCol(linha + 17, coluna + 65); printf("      ^P@@Y:         .5@@Y.   ~G@#7     ");
        linhaCol(linha + 18, coluna + 65); printf("    ~P@@Y:             ~B@#!    7&@P^   ");
        linhaCol(linha + 19, coluna + 65); printf("  ~P@&J:                 ?&@P~^^^!B@@J. ");
        linhaCol(linha + 20, coluna + 65); printf("^P@@Y:                    :P@@@@@@@@@@B!");

        mudarRedes = true;
        Sleep(2000);
        mudarRedes = false;

        textColor(LIGHTMAGENTA, _BLACK);
        box(9, coluna + 68, 12, coluna + 100);

        textColor(BROWN, _BLACK);
        linhaCol(linha, coluna + 70); printf("Siga as minhas redes sociais!");
        linhaCol(linha + 1, coluna + 72); printf("Instagram: @gui.scordeiro");

        textColor(BLUE, _BLACK);
        linhaCol(linha + 4, coluna + 62); printf("           .~?Y55555555555555Y?~.           ");textColor(MAGENTA, _BLACK);
        linhaCol(linha + 5, coluna + 62); printf("        :P@@@@&&&&&&&&&&&&&&&&@@@@P:        ");
        linhaCol(linha + 6, coluna + 62); printf("      .B@@G~.                   ^G@@B.      ");
        linhaCol(linha + 7, coluna + 62); printf("     .&@&:                   7BB~ :&@&.     ");
        linhaCol(linha + 8, coluna + 62); printf("     G@@:        .~YGBBGY!.  B@@G  :@@G     ");
        linhaCol(linha + 9, coluna + 62); printf("     &@&       ^B@@@#GGB&@@#! ..    &@&     ");
        linhaCol(linha + 10, coluna + 62); printf("     &@&      5@@G:      .Y@@B      &@&     ");
        linhaCol(linha + 11, coluna + 62); printf("     &@&     7@@?          ^@@P     &@&     ");textColor(LIGHTMAGENTA, _BLACK);
        linhaCol(linha + 12, coluna + 62); printf("     &@&     B@@            &@&     &@&     ");
        linhaCol(linha + 13, coluna + 62); printf("     &@&     ?@@7          ^@@G     &@&     ");
        linhaCol(linha + 14, coluna + 62); printf("     &@&      P@@P.      .J@@#      &@&     ");
        linhaCol(linha + 15, coluna + 62); printf("     &@&       ~#@@&BPPG&@@&7       &@&     ");
        linhaCol(linha + 16, coluna + 62); printf("     G@@:        .!5B##BP7:        :@@G     ");textColor(RED, _BLACK);
        linhaCol(linha + 17, coluna + 62); printf("     .&@&:                        :&@&.     ");
        linhaCol(linha + 18, coluna + 62); printf("      .B@@G~.                  .~G@@B.      ");
        linhaCol(linha + 19, coluna + 62); printf("        :P@@@@&&&&&&&&&&&&&&&&@@@@P:        ");textColor(BROWN, _BLACK);
        linhaCol(linha + 20, coluna + 62); printf("           .~?Y55555555555555Y?~.           ");
        textColor(WHITE, _BLACK);

        mudarRedes = true;
        Sleep(4000);
        mudarRedes = false;

        textColor(BLUE, _BLACK);
        box(9, coluna + 68, 12, coluna + 100);

        textColor(BLUE, _BLACK);
        linhaCol(linha, coluna + 70); printf("Siga as minhas redes sociais!");
        linhaCol(linha + 1, coluna + 73); printf("LinkedIn: @gui-cordeiro");

        linhaCol(linha + 4, coluna + 66); printf(" .YB##P^                            ");
        linhaCol(linha + 5, coluna + 66); printf("~@@@@@@@Y                           ");
        linhaCol(linha + 6, coluna + 66); printf("?@@@@@@@#                           ");
        linhaCol(linha + 7, coluna + 66); printf(" J&@@@@P.                           ");
        linhaCol(linha + 8, coluna + 66); printf("   ...                              ");
        linhaCol(linha + 9, coluna + 66); printf(" ^^^^^^~     ^~^^^~:   ^7Y55Y?~.    ");
        linhaCol(linha + 10, coluna + 66); printf(" @@@@@@@~   .@@@@@@&:G@@@@@@@@@@#~  ");
        linhaCol(linha + 11, coluna + 66); printf(" @@@@@@@^   .@@@@@@@@@@@@@@@@@@@@@Y ");
        linhaCol(linha + 12, coluna + 66); printf(" @@@@@@@^   .@@@@@@@@@GJ?JB@@@@@@@@:");
        linhaCol(linha + 13, coluna + 66); printf(" @@@@@@@^   .@@@@@@@B      ^@@@@@@@?");
        linhaCol(linha + 14, coluna + 66); printf(" @@@@@@@^   .@@@@@@@:       #@@@@@@5");
        linhaCol(linha + 15, coluna + 66); printf(" @@@@@@@^   .@@@@@@@.       B@@@@@@5");
        linhaCol(linha + 16, coluna + 66); printf(" @@@@@@@^   .@@@@@@@.       B@@@@@@5");
        linhaCol(linha + 17, coluna + 66); printf(" @@@@@@@^   .@@@@@@@.       B@@@@@@5");
        linhaCol(linha + 18, coluna + 66); printf(" @@@@@@@^   .@@@@@@@.       B@@@@@@5");
        linhaCol(linha + 19, coluna + 66); printf(" @@@@@@@^   .@@@@@@@.       B@@@@@@5");
        linhaCol(linha + 20, coluna + 66); printf(" B&####&:   .#&###&#.       Y&####&?");
        textColor(WHITE, _BLACK);

        mudarRedes = true;
        Sleep(4000);
        mudarRedes = false;
    }
}

DWORD WINAPI antiCheat(LPVOID params) {
    HANDLE hConsole = GetStdHandle(STD_INPUT_HANDLE);
    while (1) {
        DWORD consoleMode;
        GetConsoleMode(hConsole, &consoleMode);
        if (consoleMode & ENABLE_QUICK_EDIT_MODE) {
            if (!isTextEditingEnabled) {
                isTextEditingEnabled = true;
                mostrarLetras = false;
            }
        } else {
            if (isTextEditingEnabled) {
                isTextEditingEnabled = false;
                mostrarLetras = true;
            }
        }
        Sleep(100); // Aguarda meio segundo antes de verificar novamente
    }
}

DWORD WINAPI bannerParabens(LPVOID params) {
    bool corTrocada = false;
    while(!(GetAsyncKeyState(VK_RETURN) & 0x8000)) {
        if (!corTrocada) textColor(LIGHTGREEN, _BLACK);
        else textColor(WHITE, _BLACK);
        linhaCol(19, 89); printf(" __                    ");
        linhaCol(20, 89); printf("/_/                 __ ");
        linhaCol(21, 52); printf(" _____  _____  _____  _____  _____  _____  _____  _____ |  |");
        linhaCol(22, 52); printf("|  _  ||  _  || __  ||  _  || __  ||   __||   | ||   __||  |");
        linhaCol(23, 52); printf("|   __||     ||    -||     || __ -||   __|| | | ||__   ||__|");
        linhaCol(24, 52); printf("|__|   |__|__||__|__||__|__||_____||_____||_|___||_____||__|");
        Sleep(350);
        corTrocada = !corTrocada;
    }
}

DWORD WINAPI bannerEncerramento(LPVOID params) {
    while(1) {
        textColor(BROWN, _BLACK);
        if (modosDisponiveis == 1) {
            exibirBannerDificuldade("ESSA FOI FÁCIL, MAS AGORA AS COISAS VÃO", 35, 7, "MÉDIO I", 33, 62);
            linhaCol(36, 12);printf("DIFICULTAR UM POUCO! VÁ AGORA AO: ");
        } else if (modosDisponiveis == 2) {
            exibirBannerDificuldade("SIGA ADIANTE! CONTINUE O SEU APRENDIZADO NO:", 35, 5, "MÉDIO II", 33, 59);
        } else if (modosDisponiveis == 3) {
            exibirBannerDificuldade("MUITO BEM! AGORA VÁ ADIANTE AO SEU ÚLTIMO", 35, 6, "DIFÍCIL", 33, 65);
            linhaCol(36, 10);printf("DESAFIO. AO INIGUALÁVEL, AO TEMÍVEL:");
        } else if (modosDisponiveis == 4) {
            //exibirBannerDificuldade("", 0, 0, "AGRADECIMENTO", 33, 27); //Frase do Nível Livre
            setlocale(LC_ALL, "C");
            linhaCol(35, 40); printf("%c ", 254);
            setlocale(LC_ALL, "Portuguese");
            printf("Pressione Enter para retornar ao Menu");
            setlocale(LC_ALL, "C");
            printf(" %c   ", 254);
            setlocale(LC_ALL, "Portuguese");
        }
        textColor(WHITE, _BLACK);
        Sleep(3500);

        while (!mudarRedes) {Sleep(1000);}

        if (modosDisponiveis != 4) { //Retirar no futuro quando o Modo Livre for criado
            textColor(BROWN, _BLACK);
            setlocale(LC_ALL, "C");
            linhaCol(35, 2); printf("      %c ", 254);
            setlocale(LC_ALL, "Portuguese");
            printf("Pressione Enter para retornar ao Menu");
            setlocale(LC_ALL, "C");
            printf(" %c     ", 254);
            linhaCol(36, 5);
            printf("                                            ");
            setlocale(LC_ALL, "Portuguese");
            textColor(WHITE, _BLACK);
            Sleep(1500);
        }

        while (!mudarRedes) {Sleep(1000);}
    }
}
