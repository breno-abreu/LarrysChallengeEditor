#include "LarrysChallenge.h"

LarrysChallenge::LarrysChallenge()
{
	
	RenderWindow window(VideoMode(500, 500), "Larry's Challenge Editor", Style::Close);
	gerenciadorFase = new GerenciadorFase(&window);
	gerenciadorFase->adicionar_entidade(10, 10, "Caixa");
	gerenciadorFase->adicionar_entidade(40, 10, "Caixa");
	gerenciadorFase->adicionar_entidade(10, 50, "Caixa");
	gerenciadorFase->adicionar_entidade(200, 200, "Caixa");

	while (window.isOpen()) {

		Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type) 
			{
			case Event::Closed:
				window.close();
				break;
			}
		}
		window.clear();
		gerenciadorFase->executar_fase(10, 10);
		window.display();
	}
}


LarrysChallenge::~LarrysChallenge()
{
}
