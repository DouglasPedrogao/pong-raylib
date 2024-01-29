#include "raylib.h"

// Mover o primeiro player
void MovePlayer1(Rectangle *rect, float vel);

// Mover o segundo player
void MovePlayer2(Rectangle *rect, float vel);

// Calcular o score
void CalcScore(int *score, Rectangle *ball, int screenWidth, int screenHeight);

int main(int argc, char** argv) {
  
  int screenHeight = 600;
  int screenWidth  = 1000;
	float velPlayer = 6.0f;
  
	// Abre a janela
  InitWindow(screenWidth, screenHeight, "Raylib Test");
  
	// Parametros para a criaçao do player1
	Rectangle rect1 = {950.0f, (float)screenHeight/2 - 50, 25, 125};
	int score1 = 0;
	
	// Parametros para a criaçao do player2
	Rectangle rect2 = {25.0f, (float)screenHeight/2 - 50, 25, 125};
	int score2 =0;
	
	// Parametros para a criaçao da bola
	Rectangle ball = {(float)screenWidth/2 - 10, (float)screenHeight/2 - 10, 20, 20};
	Vector2 velBall = {0, 0};
	
	SetTargetFPS(60);
	
  while(!WindowShouldClose()){
		
		// Logica para comecar a bola
		if(IsKeyDown(KEY_ENTER)) {
			velBall.x = 5;
			velBall.y = 5;
		}
		
		// Logica para mover o player 1
		MovePlayer1(&rect1, velPlayer);
		
		// Logica para mover o player 2
		MovePlayer2(&rect2, velPlayer);
		
		// Logica para mover a bola
		if(ball.y >= 580 || ball.y <= 0) velBall.y *= -1;
		if(CheckCollisionRecs(ball, rect1) || CheckCollisionRecs(ball, rect2)) velBall.x *= -1;
		if(ball.x >= 980){
			CalcScore(&score2, &ball, screenWidth, screenHeight);
		} 
		if(ball.x <= 0){ 
			CalcScore(&score1, &ball, screenWidth, screenHeight);
		}
		ball.y += velBall.y;
		ball.x += velBall.x;
		
		// Começa a desenhar
    BeginDrawing();
		
		ClearBackground(BLACK);
		DrawLine(screenWidth/2, 0, screenWidth/2, 1000, LIGHTGRAY);
		DrawText(TextFormat("%d", score1), 550, 20, 50, WHITE);
		DrawText(TextFormat("%d", score2), 425, 20, 50, WHITE);
		DrawRectangleRec(rect1, WHITE);
		DrawRectangleRec(rect2, WHITE);
		DrawRectangleRec(ball, WHITE);
		
		// Termina de desenhar
		EndDrawing();
  }
  
	// Fecha a janela
  CloseWindow();
  
  return 0;
}

// Mover o primeiro player
void MovePlayer1(Rectangle *rect, float vel){
	if(IsKeyDown(KEY_UP) && rect->y >= 10) rect->y -= vel;
	if(IsKeyDown(KEY_DOWN) && rect->y <= 460) rect->y += vel;
}

// Mover o segundo player
void MovePlayer2(Rectangle *rect, float vel){
	if(IsKeyDown(KEY_W) && rect->y >= 10) rect->y -= vel;
	if(IsKeyDown(KEY_S) && rect->y <= 460) rect->y += vel;
}

// Calcular o score
void CalcScore(int *score, Rectangle *ball, int screenWidth, int screenHeight){
	*score += 1;
	ball->x = screenWidth/2;
	ball->y = screenHeight/2;
	WaitTime(1);
}