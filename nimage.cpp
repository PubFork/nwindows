public class NImage{
 	vector<string> strings;
 	vector<COLOR>  colors;
 	int len_x, len_y;

 	public:
 		Nimage();
 		Nimage(FILE* f);
 		~Nimage();
}nimage;

/*empty image object constructor */
Nimage :: Nimage(){
	len_y = 0;
	len_x = 0;
}

/*image constructor with file of ascii art*/
Nimage :: Nimage(FILE* f){

}

