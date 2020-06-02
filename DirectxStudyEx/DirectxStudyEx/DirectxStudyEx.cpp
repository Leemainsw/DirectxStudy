// DirectxStudyEx.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "DirectxStudyEx.h"
#include "Global.h"

#define MAX_LOADSTRING 100 

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.


// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

// 함수 초기화
void Render();
void Update();
void InitRsc();
HRESULT InitD3D(HWND hWnd);

// 변수 초기화
LPDIRECT3D9 g_pD3D = nullptr;
LPDIRECT3DDEVICE9 g_pd3dDevice = nullptr;

DWORD prevTime;
DWORD deltaTime;

Texture_Manager textureManager;
Stage_Manager stageManager;


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_DIRECTXSTUDYEX, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DIRECTXSTUDYEX));

    // 기본 메시지 루프입니다:
    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            Update();
            Render();
        }

    }

    return (int)msg.wParam;
}

void InitRsc() 
{
    //textureManager.LoadTexture(L"texture.png", 1);
    textureManager.LoadTexture(L"title.png", TEX_TITLE_SCREEN, 0,  680, 0, 480);
    //textureManager.LoadTexture(L"background.png", GAME_BACKGROUND, 0, width, 0, height);
    //textureManager.LoadTexture(L"player1.png", GAME_PLAYER_BODY, 0, width, 0, height);
    //textureManager.LoadTexture(L"player_bullet_1.png", GAME_PLAYER_BULLET_1, 0, width, 0, height);

    //textureManager.LoadTexture(L"enemy_a.png", GAME_ENEMY_A_BODY, 0, width, 0, height);
    //textureManager.LoadTexture(L"enemy_b.png", GAME_ENEMY_B_BODY, 0, width, 0, height);

    //textureManager.LoadTexture(L"explosion.png", GAME_ENEMY_EXPLOSION, 0, width, 0, height);

    //textureManager.LoadTexture(L"boss_a.png", GAME_ENEMY_BOSS_A_BODY, 0, width, 0, height);
    //textureManager.LoadTexture(L"boss_bullt_a.png", GAME_ENEMY_BOSS_A_BULLET_1, 0, width, 0, height);

    stageManager.MakeTitleStage();
    prevTime = GetTickCount();
}

void Update()
{
    stageManager.Update();
    DWORD current = GetTickCount();
    DWORD diff = current - prevTime;
    deltaTime = diff / (1000.f);

    if (deltaTime > 0.016)
    {
        deltaTime = 0.016f;
    }

    prevTime = current;
}

void Render() 
{
   
    // Clear the backbuffer and the zbuffer
    g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, //| D3DCLEAR_ZBUFFER,
        D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

    // Begin the scene
    if (SUCCEEDED(g_pd3dDevice->BeginScene()))
    {
        stageManager.Render();

        D3DXVECTOR3 pos(0, 0, 0);

       /* textureManager.GetTexture(PLAYER)->sprite->Begin(D3DXSPRITE_ALPHABLEND);

        textureManager.GetTexture(PLAYER)->sprite->Draw(textureManager.GetTexture(PLAYER)->texture, &textureManager.GetTexture(PLAYER)->rect, nullptr, &pos,
            D3DCOLOR_XRGB(255, 255, 255));


        textureManager.GetTexture(PLAYER)->sprite->End();*/


        // End the scene
        g_pd3dDevice->EndScene();
    }

    g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

HRESULT InitD3D(HWND hWnd)
{
    // Create the D3D object.
    if (NULL == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
        return E_FAIL;

    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory(&d3dpp, sizeof(d3dpp));

    d3dpp.Windowed = TRUE; //전체화면 하려면  false로 지정

    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;

    // Create the D3DDevice
    if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING,
        &d3dpp, &g_pd3dDevice)))
    {
        return E_FAIL;
    }

    return S_OK;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DIRECTXSTUDYEX));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = nullptr; // MAKEINTRESOURCEW(IDC_DIRECTXSTUDYEX);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, WINDOW_WIDTH, WIDTH_HEIGHT, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }
   
   InitD3D(hWnd);
   InitRsc();

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

