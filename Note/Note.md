# 이곳은 DirectX 필기하는 공간입니다.

## ⚙ DirectX 프로젝트 초기 설정 ⚙

### 속성
- 포함 디렉터리
- 라이브러리 디렉터리 설정  
- 추가 포함 디렉터리
  - 링커 -> 입력에서 
  - ```C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Samples\C++\Direct3D\Tutorials```
  - 에서 추가 종속성 가져오기

### 코드 
- WndProc에서 WM_COMMED 삭제
- CALLBACK About 삭제
- MyRegisterClass에서  wcex.lpszMenuName   = nullptr; ... menu 부분을 없애준다.
- InitInstance에서 InitD3D()를 추가해준다.
- wWinMain에서 ```C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Samples\C++\Direct3D\Tutorials``` 을 보고 따라한다. 
- InitInstance에서 init3d()를 호출해준다.
- HwND 초기화 할 때 window_width, window_height를 지정한다.
- wWinMain에서 update()와 render()를 추가한다.
- tutorials에서 render 따라한다.
  - ```cpp 
    g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, //| D3DCLEAR_ZBUFFER,
        D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);```
- Global.h 만들기
- 게임 width, height 정의하기
- LPDIRECT3D9, LPDIRECT3DDEVICE9 extern 설정

## 🎨 화면에 그림 띄우기 🎨
- TextureManager.h 만들기
- TEXTUREMANAGER.H 
- textureObject 만들기
- id, sprite, texture, rect 정의하기
- LoadTexture, GetTexture 정의하기
- InitRsc() 만들기
- LoadTexture 호출하기 
- Render에서 
```cpp
  textureManager.GetTexture(PLAYER)->sprite->Begin(D3DXSPRITE_ALPHABLEND);
  textureManager.GetTexture(PLAYER)->sprite->Draw(textureManager.GetTexture(PLAYER)->texture, &textureManager.GetTexture(PLAYER)->rect, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));
  textureManager.GetTexture(PLAYER)->sprite->End();
```

## ⏰ DeltaTime 적용하기 ⏰
- 자료형은 DWORD
- prevTime 선언
- GetTickCount(); prevTime에 적용 (initstuff에서)
- Update 할 때마다
```cpp
  DWORD cur = GetTickCount();    
    DWORD diff = cur - prevTime;
    deltaTime = diff / (1000.0f);

    if (deltaTime > 0.016)
    {
        deltaTime = 0.016f;
    }

    prevTime = cur;
```
- deltaTime은 extern으로 global에 정의

## ⏰ Stage 나누기 ⏰
- stageManager 생성
- stage 생성
- make titlestage() 
- make gamestage()
- make update(), render()

**stageManager** 
- currentStage 
- update
- render

**TitleStage**
- Update 
  - 마우스 클릭했을 때 GameStage로 넘어가기
- Render
  - texture 가져와서 찍기

**GameStage**
- Update
- Render

## ✒ 입력 메니저 ✒

**InpuyManager**
- Input_Manager.h 파일 생성 (cpp제외)
- global.h에 넣기
- prevKeyBuffer[256], keyBuffer[256]
- update() 함수에서 prevKeyBuffer[i] = keyBuffer[i];
- CALLBACK WndProc 에서 LButtonDown, LButtonUp 일 경우 코드 작성하기 