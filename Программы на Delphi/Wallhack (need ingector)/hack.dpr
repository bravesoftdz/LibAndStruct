library hack;

uses
	Windows,
	Classes,
	advApiHook,
	Direct3D9,
	D3DX9;

var
	g_Font  : ID3DXFont;
	TextRect: TRect;
	StridesN: integer;
	Wallhack: boolean; //���������/���������� ����

var EndScene9Next :           function (self: pointer): HResult stdcall;
var CreateDevice9Next:        function (self: pointer; Adapter: LongWord; DeviceType: TD3DDevType; hFocusWindow: HWND; BehaviorFlags: DWord; pPresentationParameters: PD3DPresentParameters; out ppReturnedDeviceInterface: IDirect3DDevice9): HResult; stdcall;
var Direct3DCreate9Next:      function (SDKVersion: LongWord): Pointer; stdcall;

var ResetNext:                function (self: pointer; const pPresentationParameters: TD3DPresentParameters): HResult; stdcall;
var SetStreamSourceNext:      function (self: pointer; StreamNumber: LongWord; pStreamData: IDirect3DVertexBuffer9; OffsetInBytes, Stride: LongWord): HResult; stdcall;
var DrawIndexedPrimitiveNext: function (DeviceInterface: IDirect3DDevice9; _Type: TD3DPrimitiveType; BaseVertexIndex: Integer; MinVertexIndex, NumVertices, startIndex, primCount: LongWord): HResult; stdcall;

var ShowCursorNext:           function (bShow: BOOL): BOOL; stdcall;
var SetCursorPosition:        procedure(XScreenSpace, YScreenSpace: LongWord; Flags: DWord); stdcall;

procedure CheckPressed; //������� ��������� ������ ����
begin
	if ((GetAsyncKeyState(46) and 1) <> 0) then  //��� ������� �� Delete
	begin
		Wallhack:= not Wallhack;
	end;
end;

procedure All_OnLostDevice; //������� ��� ������ ������
begin
	g_Font.OnLostDevice;
end;

procedure All_OnResetDevice; //������� �� ������������� ������
begin
	g_Font.OnResetDevice;
end;

function DrawIndexedPrimitiveCallback(DeviceInterface: IDirect3DDevice9; _Type: TD3DPrimitiveType; BaseVertexIndex: Integer; MinVertexIndex, NumVertices, startIndex, primCount: LongWord): HResult; stdcall;
begin
	if (Wallhack = true) then
	begin
		DeviceInterface.SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE); //��������� ��������� �� �������
		if (StridesN = 28) and (NumVertices > 1500) then
		begin
			DeviceInterface.SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE); //��������� ��������� �� �������
			DrawIndexedPrimitiveNext(DeviceInterface, _Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
			DeviceInterface.SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE); //�������� ��������� �� �������
		end;
	end
	else
	DeviceInterface.SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);     // �������� ��������� �� �������

	Result := DrawIndexedPrimitiveNext(DeviceInterface, _Type, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
end;

function SetStreamSourceCallback(self: pointer; StreamNumber: LongWord; pStreamData: IDirect3DVertexBuffer9; OffsetInBytes, Stride: LongWord): HResult; stdcall;
begin
	StridesN := Stride;
	Result := SetStreamSourceNext(self, StreamNumber, pStreamData, OffsetInBytes, StridesN);
end;

function ResetCallback(self: pointer; const pPresentationParameters: TD3DPresentParameters): HResult; stdcall;
begin
	All_OnLostDevice;
	Result := ResetNext(self, pPresentationParameters);
	if SUCCEEDED(Result) then
	begin
		All_OnResetDevice;
	end;
end;

function ShowCursorCallback(bShow: BOOL): BOOL;
begin
	Result := ShowCursorNext(true);
	beep(400, 500);
end;


function EndScene9Callback(self: pointer): HResult; stdcall;
var
	bStr: string;
begin
	CheckPressed;
	if Wallhack then
	begin
		bStr := 'On';
	end
	else
	begin
		bStr := 'Off';
	end;    
	g_Font.DrawTextA(nil, PChar('Wallhack ' + bStr), -1, @TextRect, DT_LEFT or DT_NOCLIP, D3DCOLOR_ARGB(255, 255, 0, 0));
	Result := EndScene9Next(self);
end;

function CreateDevice9Callback(self: pointer; Adapter: LongWord; DeviceType: TD3DDevType; hFocusWindow: HWND; BehaviorFlags: DWord; pPresentationParameters: PD3DPresentParameters; out ppReturnedDeviceInterface: IDirect3DDevice9): HResult; stdcall;
begin
	Result := CreateDevice9Next(self, Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface);
	if (Result = 0) then
	begin
		TextRect := Rect(10, 10, 10, 10); //���������� �������� ������ ����
		D3DXCreateFont(ppReturnedDeviceInterface, 20, 0, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, 6, DEFAULT_PITCH or FF_DONTCARE, PChar('Arial') ,g_Font);
		HookCode(GetInterfaceMethod(ppReturnedDeviceInterface, 42),  @EndScene9Callback,            @EndScene9Next);
		HookCode(GetInterfaceMethod(ppReturnedDeviceInterface, 16),  @ResetCallback,                @ResetNext);
		HookCode(GetInterfaceMethod(ppReturnedDeviceInterface, 100), @SetStreamSourceCallback,      @SetStreamSourceNext);
		HookCode(GetInterfaceMethod(ppReturnedDeviceInterface, 82),  @DrawIndexedPrimitiveCallback, @DrawIndexedPrimitiveNext);
		HookCode(GetInterfaceMethod(ppReturnedDeviceInterface, 12),  @ShowCursorCallback,           @ShowCursorNext);
	end
end;

function Direct3DCreate9Callback(SDKVersion: LongWord): Pointer; stdcall;
begin
	Result := Direct3DCreate9Next(SDKVersion);
	if (Result <> nil) then
	begin
		if (@CreateDevice9Next <> nil) then
		begin
			UnhookCode(@CreateDevice9Next);
		end;
		HookCode(GetInterfaceMethod(result, 16), @CreateDevice9Callback, @CreateDevice9Next);
	end;
end;

procedure DLLEntryPoint(dwReason: DWord);
begin
	Case dwReason of
	DLL_PROCESS_ATTACH:
		begin
		{ ��� ������� ����������� �������� ������� Direct3DCreate9,
		����������� � ���������� d3d9.dll
		� �������� �� �� ����� ������� Direct3DCreate9Callback }
		HookProc('d3d9.dll', 'Direct3DCreate9', @Direct3DCreate9Callback, @Direct3DCreate9Next);
		end;
	DLL_PROCESS_DETACH:
		begin
	
		end;
	end;
end;

begin
	DllProc := @DLLEntryPoint; //������������� ������������ ����������
	DLLEntryPoint(DLL_PROCESS_ATTACH);
end.