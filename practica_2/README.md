# Práctica 2: Informática gráfica 19/20

## Uso

### Figuras
    swith(tecla) {
        case GLUT_KEY_F1:
        figure = cubo;
        break; // Cubo
    
        case GLUT_KEY_F2:
            figure = tetraedro;
            break; // Tetraedro
        
        case GLUT_KEY_F3:
            figure = ply;
            break; //objeto ply
        
        case GLUT_KEY_F4:
            figure = revolucion;
            break;
        
        case GLUT_KEY_F5:
            figure = cilind;
            break;
        
        case GLUT_KEY_F6:
            figure = vas_inv;
            break;
        
        case GLUT_KEY_F7:
            figure = esfera;
            break;
        
        case GLUT_KEY_F8:
            figure = tube;
            break;
        
        case GLUT_KEY_F9:
            figure = vas;
            break;
        
        case GLUT_KEY_F10:
            figure = cone;
            break;

        case GLUT_KEY_LEFT:
            Observer_angle_y--;
            break;
        case GLUT_KEY_RIGHT:
            Observer_angle_y++;
            break;
        case GLUT_KEY_UP:
            Observer_angle_x--;
            break;
        case GLUT_KEY_DOWN:
            Observer_angle_x++;
            break;
        case GLUT_KEY_PAGE_UP:
            Observer_distance *= 1.2;
            break;
        case GLUT_KEY_PAGE_DOWN:
            Observer_distance /= 1.2;
            break;
    }

### Modos de visualización

    case 'Q':
            exit(0);
            break;
        case 'P': //vertices
            vertice = !vertice;
            break;
        case 'L': //aristas
            arista = !arista;
            break;
        case 'S': //lados
            solid = !solid;
            chess = false;
            break;
        case 'A': //ajedrez
            chess = !chess;
            solid = false;
            break;
