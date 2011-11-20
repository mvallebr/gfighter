unit formMain;

interface

uses
  SysUtils, Types, Classes, Variants, QTypes, QGraphics, QControls, QForms,
  QDialogs, QStdCtrls, QMenus, QExtCtrls, QComCtrls, QImgList, Qt,
  unitSprite,
  unitAction, unitFrame, unitInput,
  unitPoly, unitTrajectory, unitTrajPoint, unitTrigger,
  QFileCtrls, QGrids, XMLDoc, XMLIntf;

type
  TfrmMain = class(TForm)
    PageControl1: TPageControl;
    TabSheet1: TTabSheet;
    Panel1: TPanel;
    TabSheet2: TTabSheet;
    TabSheet3: TTabSheet;
    TabSheet4: TTabSheet;
    MainMenu1: TMainMenu;
    Sprite1: TMenuItem;
    Exit1: TMenuItem;
    Help1: TMenuItem;
    About1: TMenuItem;
    ToolBar1: TToolBar;
    ToolButton1: TToolButton;
    ToolButton2: TToolButton;
    imgStdButtons: TImageList;
    lstActions: TListBox;
    Panel2: TPanel;
    Panel3: TPanel;
    ToolBar2: TToolBar;
    ToolButton3: TToolButton;
    ToolButton4: TToolButton;
    Panel4: TPanel;
    Splitter1: TSplitter;
    Panel5: TPanel;
    Panel6: TPanel;
    ToolBar4: TToolBar;
    ToolButton5: TToolButton;
    ToolButton6: TToolButton;
    lstPolys: TListBox;
    Splitter2: TSplitter;
    pgProperties: TPageControl;
    tabAction: TTabSheet;
    tabFrame: TTabSheet;
    tabPoly: TTabSheet;
    Panel7: TPanel;
    ToolBar5: TToolBar;
    ToolButton7: TToolButton;
    ToolButton8: TToolButton;
    lstInputs: TListBox;
    Panel8: TPanel;
    Panel12: TPanel;
    Panel10: TPanel;
    ToolBar8: TToolBar;
    ToolButton11: TToolButton;
    ToolButton12: TToolButton;
    lstStates: TListBox;
    Panel11: TPanel;
    ToolBar9: TToolBar;
    ToolButton13: TToolButton;
    ToolButton14: TToolButton;
    lstTriggers: TListBox;
    lstFrames: TListBox;
    TabSheet5: TTabSheet;
    TabSheet6: TTabSheet;
    edtBaseFolder: TEdit;
    Label1: TLabel;
    dtvBaseFolder: TDirectoryTreeView;
    GroupBox1: TGroupBox;
    btnLoadFile: TButton;
    btnSaveFile: TButton;
    Label2: TLabel;
    lbTrigger: TLabel;
    edtActionTrigger: TEdit;
    edtNextAction: TEdit;
    edtActionSoundFile: TEdit;
    Label3: TLabel;
    lb4: TLabel;
    edtFrameState: TEdit;
    lb3: TLabel;
    lb2: TLabel;
    edtFrameCenterX: TEdit;
    lb1: TLabel;
    edtFrameCenterY: TEdit;
    btnCenter: TButton;
    Panel13: TPanel;
    Panel14: TPanel;
    ScrollBox1: TScrollBox;
    imgFrame: TImage;
    imgCenter: TShape;
    chkShowPolys: TCheckBox;
    Label4: TLabel;
    edtPolyPriority: TSpinEdit;
    edtPolyP1X: TSpinEdit;
    Label5: TLabel;
    edtPolyP1Y: TSpinEdit;
    Label6: TLabel;
    edtPolyP2X: TSpinEdit;
    Label7: TLabel;
    edtPolyP2Y: TSpinEdit;
    Label8: TLabel;
    edtPolyP4Y: TSpinEdit;
    Label9: TLabel;
    edtPolyP4X: TSpinEdit;
    edtPolyP3Y: TSpinEdit;
    edtPolyP3X: TSpinEdit;
    Label10: TLabel;
    Label11: TLabel;
    Label12: TLabel;
    edtFrameImageFile: TFileEdit;
    P1: TShape;
    P2: TShape;
    P3: TShape;
    P4: TShape;
    Edit1: TMenuItem;
    Refresh1: TMenuItem;
    Panel15: TPanel;
    chkFrameCenter: TCheckBox;
    Label13: TLabel;
    edtPolyTrigger: TEdit;
    Panel16: TPanel;
    ToolBar3: TToolBar;
    ToolButton15: TToolButton;
    ToolButton16: TToolButton;
    lstTrajectories: TListBox;
    Panel17: TPanel;
    Panel18: TPanel;
    ToolBar7: TToolBar;
    ToolButton17: TToolButton;
    ToolButton18: TToolButton;
    lstPoints: TListBox;
    Panel19: TPanel;
    Panel20: TPanel;
    Panel27: TPanel;
    pgTrajs: TPageControl;
    tabTraj: TTabSheet;
    edtTrajWidth: TSpinEdit;
    Label22: TLabel;
    edtTrajHeight: TSpinEdit;
    Label23: TLabel;
    scrollTraj: TScrollBox;
    tabTrajPoint: TTabSheet;
    Label14: TLabel;
    edtTrajCX: TSpinEdit;
    edtTrajCY: TSpinEdit;
    Label15: TLabel;
    imgTrajectory: TImage;
    PTraj: TShape;
    Splitter4: TSplitter;
    grdInputs: TStringGrid;
    Label16: TLabel;
    edtTrajTrigger: TEdit;
    edtTrajTime: TSpinEdit;
    Label17: TLabel;
    Label18: TLabel;
    edtTrajAFrames: TSpinEdit;
    Button3: TButton;
    Panel9: TPanel;
    edtInputTrigger: TEdit;
    Label19: TLabel;
    edtNextTraj: TEdit;
    Label20: TLabel;
    Panel21: TPanel;
    edtTrigger: TMemo;
    lbTriggerName: TLabel;
    Label24: TLabel;
    edtInputTrigger2: TEdit;
    Label21: TLabel;
    procedure Exit1Click(Sender: TObject);
    procedure ToolButton1Click(Sender: TObject);
    procedure lstActionsClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure ToolButton3Click(Sender: TObject);
    procedure ToolButton5Click(Sender: TObject);
    procedure lstFramesClick(Sender: TObject);
    procedure dtvBaseFolderChange(Sender: TObject; Node: TTreeNode);
    procedure btnCenterClick(Sender: TObject);
    procedure edtFrameImageFileReturnPressed(Sender: TObject);
    procedure imgFrameDragOver(Sender, Source: TObject; X, Y: Integer;
      State: TDragState; var Accept: Boolean);
    procedure P1EndDrag(Sender, Target: TObject; X, Y: Integer);
    procedure P1DragOver(Sender, Source: TObject; X, Y: Integer;
      State: TDragState; var Accept: Boolean);
    procedure lstPolysClick(Sender: TObject);
    procedure Refresh1Click(Sender: TObject);
    procedure chkFrameCenterClick(Sender: TObject);
    procedure chkShowPolysClick(Sender: TObject);
    procedure edtPolyP1XChanged(Sender: TObject; NewValue: Integer);
    procedure ToolButton15Click(Sender: TObject);
    procedure ToolButton17Click(Sender: TObject);
    procedure lstTrajectoriesClick(Sender: TObject);
    procedure lstPointsClick(Sender: TObject);
    procedure edtTrajCXChanged(Sender: TObject; NewValue: Integer);
    procedure edtTrajCYChanged(Sender: TObject; NewValue: Integer);
    procedure PTrajDragOver(Sender, Source: TObject; X, Y: Integer;
      State: TDragState; var Accept: Boolean);
    procedure PTrajEndDrag(Sender, Target: TObject; X, Y: Integer);
    procedure imgTrajectoryDragOver(Sender, Source: TObject; X, Y: Integer;
      State: TDragState; var Accept: Boolean);
    procedure edtTrajWidthChanged(Sender: TObject; NewValue: Integer);
    procedure edtTrajHeightChanged(Sender: TObject; NewValue: Integer);
    procedure ToolButton11Click(Sender: TObject);
    procedure ToolButton12Click(Sender: TObject);
    procedure ToolButton13Click(Sender: TObject);
    procedure ToolButton14Click(Sender: TObject);
    procedure lstTriggersClick(Sender: TObject);
    procedure grdInputsSetEditText(Sender: TObject; ACol, ARow: Integer;
      const Value: WideString);
    procedure grdInputsDrawCell(Sender: TObject; ACol, ARow: Integer;
      Rect: TRect; State: TGridDrawState);
    procedure ToolButton7Click(Sender: TObject);
    procedure ToolButton8Click(Sender: TObject);
    procedure lstInputsClick(Sender: TObject);
    procedure ToolButton18Click(Sender: TObject);
    procedure edtTrajTriggerChange(Sender: TObject);
    procedure ToolButton16Click(Sender: TObject);
    procedure ToolButton2Click(Sender: TObject);
    procedure ToolButton6Click(Sender: TObject);
    procedure ToolButton4Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure btnSaveFileClick(Sender: TObject);
    procedure btnLoadFileClick(Sender: TObject);
    procedure edtNextTrajChange(Sender: TObject);
    procedure lstActionsDblClick(Sender: TObject);
    procedure lstTrajectoriesDblClick(Sender: TObject);
    procedure lstInputsDblClick(Sender: TObject);
    procedure lstTriggersDblClick(Sender: TObject);
  private
    { Private declarations }
    old_action: TAction;
    old_frame:  TFrame;
    old_poly:   TPoly;
    selPolyColor, PolyColor: TColor;

    old_traj:        TTrajectory;
    old_trajpoint:   TTrajPoint;

    old_trigger:     TTrigger;

    old_input:        TInput;

    //Set to true to disable changed event on poly properties
    editing_poly: boolean;
    procedure updateFrames(frames: Tlist);
    function  getCurrentAction: TAction;
    function  getCurrentFrame: TFrame;
    function  getCurrentPoly: TPoly;
    procedure updateCurrentAction;
    procedure updateCurrentFrame;
    procedure updateCurrentFrameGUI;
    procedure updateCurrentPoly;
    procedure updateCurrentPolyGUI;
    procedure ShowCurrentFramePolys;

    procedure updateCurrentTrajectory;
    procedure drawTrajectoryPoints;
    procedure updateCurrentTrajPoint;
    function  getCurrentTrajectory: TTrajectory;
    function  getCurrentTrajPoint: TTrajPoint;

    procedure resetCurrentInput;
  public
    { Public declarations }
  end;

var
  frmMain: TfrmMain;

implementation

uses formTestAction;

{$R *.xfm}


procedure TfrmMain.Exit1Click(Sender: TObject);
begin
  Close;
end;

procedure TfrmMain.ToolButton1Click(Sender: TObject);
var
  action: TAction;
  texto : string;
begin
  texto := 'Action'+IntToStr(lstActions.Items.Count);
  texto := inputbox('New action', 'Please, type the name of the new action:', texto);
  if (length(texto)=0) then exit;
  action := TAction.Create(texto);
  lstActions.ItemIndex:=lstActions.Items.Add(texto);
  lstActions.Items.Objects[lstActions.ItemIndex] := action;
  updateCurrentAction;
  updateCurrentFrame;
  updateCurrentPoly;
end;

procedure TfrmMain.updateFrames(frames: Tlist);
var
  i: integer;
  frame:  TFrame;
begin
  //Update list of frames in GUI
  lstFrames.Clear;
  for i := 0 to frames.Count -1 do begin
    frame := TFrame(frames.Items[i]);
    lstFrames.ItemIndex:=lstFrames.Items.Add(frame.caption);
    lstFrames.Items.Objects[lstFrames.ItemIndex] := frame;
  end;
  //updateRects;
end;

procedure TfrmMain.lstActionsClick(Sender: TObject);
begin
  updateCurrentAction;
  updateCurrentFrame;
  updateCurrentPoly;
end;

function  TfrmMain.getCurrentAction: TAction;
var
  action : TAction;
begin
  // Return the current select action or nil if no action is selected
  if lstActions.ItemIndex<0 then begin
    Result := nil;
    exit;
  end;
  action := TAction(lstActions.Items.Objects[lstActions.ItemIndex]);
  Result := action;
end;

function  TfrmMain.getCurrentFrame: TFrame;
var
  frame: TFrame;
begin
  // Return the current select frame or nil if no frame is selected
  Result := nil;
  if lstFrames.ItemIndex<0 then exit;
  frame := TFrame(lstFrames.Items.Objects[lstFrames.ItemIndex]);
  Result := frame;
end;

function  TfrmMain.getCurrentPoly: TPoly;
var
  poly: TPoly;
begin
  // Return the current select frame or nil if no frame is selected
  Result := nil;
  if lstPolys.ItemIndex<0 then exit;
  poly := TPoly(lstPolys.Items.Objects[lstPolys.ItemIndex]);
  Result := poly;
end;

procedure TfrmMain.FormCreate(Sender: TObject);
const
  psize = 9;
var
  bmp:TBitmap;
begin
  edtTrigger.BorderStyle := bsNone;
  dtvBaseFolder.Directory := ExtractFilePath(Application.ExeName);
  dtvBaseFolderChange(Sender, nil);
  old_action  :=nil;
  old_frame   :=nil;
  old_poly    :=nil;
  updateCurrentPolyGUI;
  p1.Width := psize;p2.Width := psize;p3.Width := psize;p4.Width := psize;
  p1.Height:= psize;p2.Height:= psize;p3.Height:= psize;p4.Height:= psize;
  selPolyColor  := clRed;
  PolyColor     := clBlue;

  old_traj      :=nil;
  old_trajpoint :=nil;

  bmp := TBitmap.Create;
  bmp.Width := imgTrajectory.Width;
  bmp.Height := imgTrajectory.Height;
  imgTrajectory.Picture := TPicture.Create;
  imgTrajectory.Picture.Bitmap := bmp;

  old_trigger := nil;

  old_input:=nil;
  resetCurrentInput;
end;

procedure TfrmMain.ToolButton3Click(Sender: TObject);
var
  action : TAction;
  texto:   String;
  frame:   TFrame;
begin
  action := getCurrentAction;
  if (action = nil) then begin
    ShowMessage('Please, select an action first!');
    exit;
  end;
  texto := 'F'+IntToStr(lstFrames.Items.Count);
  texto := inputbox('New Frame', 'Please, type the name of the new frame:', texto);
  if (length(texto)=0) then exit;
  frame := TFrame.Create(texto);
  frame.ImageFile := edtFrameImageFile.Text;
  action.frames.Add(frame);
  lstFrames.ItemIndex := lstFrames.Items.Add(texto);
  lstFrames.items.Objects[lstFrames.ItemIndex] := frame;
  updateCurrentFrame;
end;

procedure TfrmMain.ToolButton5Click(Sender: TObject);
var
  frame: TFrame;
  poly:  TPoly;
  texto:   String;
begin
  frame := getCurrentFrame;
  if frame=nil then begin
    ShowMessage('Please select a frame first!');
    exit;
  end;
  if (imgFrame.Picture.Width=0) or (imgFrame.Picture.Height=0) then begin
    beep;
    ShowMessage('Insert an image first!');
    exit;
  end;
  texto := 'P'+IntToStr(lstPolys.Items.Count);
  texto := inputbox('New Poly', 'Please, type the name of the new Poly:', texto);
  if (length(texto)=0) then exit;
  poly := TPoly.Create(texto);

  poly.p1.X := imgFrame.Width div 4;
  poly.p1.Y := imgFrame.height div 4;

  poly.p2.X := 3*imgFrame.Width div 4;
  poly.p2.Y := imgFrame.height div 4;

  poly.p3.X := 3*imgFrame.Width div 4;
  poly.p3.Y := 3*imgFrame.height div 4;

  poly.p4.X := imgFrame.Width div 4;
  poly.p4.Y := 3*imgFrame.height div 4;

  frame.polys.Add(poly);
  lstPolys.ItemIndex := lstPolys.Items.Add(texto);
  lstPolys.items.Objects[lstPolys.ItemIndex] := poly;
  updateCurrentPoly;
end;

procedure TfrmMain.lstFramesClick(Sender: TObject);
begin
  updateCurrentFrame;
end;

procedure TfrmMain.updateCurrentFrame;
var
  frame : TFrame;
  poly:   TPoly;
  i: integer;
begin
  edtFrameImageFile.Text:=trim(edtFrameImageFile.Text);
  if old_frame <> nil then begin
    try
      old_frame.State := edtFrameState.Text;
      old_frame.ImageFile := edtFrameImageFile.Text;
      old_frame.Center.X  := StrToInt(edtFrameCenterX.Text);
      old_frame.Center.Y  := StrToInt(edtFrameCenterY.Text);
    except
      beep;
      ShowMessage('Error current frame properties!');
      exit;
    end;
  end;
  frame := getCurrentFrame;
  if frame=nil then begin
    lstPolys.Clear;
    exit;
  end;
  pgProperties.ActivePage := tabFrame;
  edtFrameState.Text := frame.State;
  edtFrameImageFile.Text := frame.ImageFile;
  edtFrameCenterX.Text := IntToStr(frame.Center.X);
  edtFrameCenterY.Text := IntToStr(frame.Center.Y);
  old_frame := frame;
  lstPolys.Clear;
  for i := 0 to frame.polys.Count -1 do begin
    poly := TPoly(frame.polys.Items[i]);
    lstPolys.ItemIndex:=lstPolys.Items.Add(poly.caption);
    lstPolys.Items.Objects[lstPolys.ItemIndex] := poly;
  end;
  updateCurrentFrameGUI;
  updateCurrentPoly;
end;

procedure TfrmMain.updateCurrentAction;
var
  action : TAction;
begin
  if old_action <> nil then begin
    old_action.nextAction := edtNextAction.Text;
    old_action.trigger := edtActionTrigger.Text;
    old_action.soundfile:= edtActionSoundFile.Text;
  end;
  action := getCurrentAction;
  if action=nil then exit;
  updateFrames(action.frames);
  pgProperties.ActivePage := tabAction;
  edtNextAction.Text := action.nextAction;
  edtActionTrigger.Text := action.trigger;
  edtActionSoundFile.Text := action.soundfile;
  old_action := action;
end;

procedure TfrmMain.dtvBaseFolderChange(Sender: TObject; Node: TTreeNode);
begin
  edtBaseFolder.Text := dtvBaseFolder.Directory;
  if edtBaseFolder.Text[length(edtBaseFolder.Text)]<>'\' then
        edtBaseFolder.Text := edtBaseFolder.Text + '\';
  try
    edtFrameImageFile.Directory.Location := edtBaseFolder.Text+'images\';
  except
    beep;
    ShowMessage('Error! Create the "images" folder and restart this program!');
  end;
end;

procedure TfrmMain.btnCenterClick(Sender: TObject);
begin
  edtFrameCenterX.Text := IntToStr(imgFrame.Width div 2);
  edtFrameCenterY.Text := IntToStr(imgFrame.Height div 2);
  updateCurrentFrameGUI;
end;

procedure TfrmMain.updateCurrentFrameGUI;
var
  cx, cy: integer;
  frame:  TFrame;
  picture: TPicture;
begin
  frame := getCurrentFrame;
  if frame=nil then exit;
  if edtFrameImageFile.Text='' then begin
    imgFrame.Picture.Assign(nil);
  end else begin
    try
      picture := TPicture.Create;
      if edtBaseFolder.Text[length(edtBaseFolder.Text)]<>'\' then
        edtBaseFolder.Text := edtBaseFolder.Text + '\';
      picture.LoadFromFile(edtBaseFolder.Text+'images\'+edtFrameImageFile.Text);
      imgFrame.Picture.Bitmap.Width := picture.Width;
      imgFrame.Picture.Bitmap.Height := picture.Height;
      imgFrame.Picture.Bitmap.Canvas.Brush.Color := clWhite;
      imgFrame.Picture.Bitmap.Canvas.FillRect(
        Rect(0, 0, picture.Width, picture.Height));
      imgFrame.Picture.Bitmap.Canvas.CopyMode := cmSrcCopy;
      imgFrame.Picture.Bitmap.Canvas.CopyRect(
        Rect(0, 0, picture.Width, picture.Height),
        picture.Bitmap.Canvas,
        Rect(0, 0, picture.Width, picture.Height));
      picture.Destroy;
    except
      beep;
      ShowMessage('Could not load image from file "'+
        edtBaseFolder.Text+'images\'+edtFrameImageFile.Text+
        '"!');
    end;
  end;
  try
    cx := StrToInt(edtFrameCenterX.Text);
    cY := StrToInt(edtFrameCenterY.Text);
    imgCenter.left := cx - (imgCenter.Width div 2);
    imgCenter.top  := cy - (imgCenter.Height div 2);
  except
    beep;
  end;
  imgCenter.BringToFront;
  ShowCurrentFramePolys;
end;

procedure TfrmMain.edtFrameImageFileReturnPressed(Sender: TObject);
begin
  updateCurrentFrameGUI;
end;

procedure TfrmMain.imgFrameDragOver(Sender, Source: TObject; X, Y: Integer;
  State: TDragState; var Accept: Boolean);
begin
  Accept := true;
  if state = dsDragMove	 then begin
    try
      TShape(Source).Left := X - (TShape(Source).Width div 2);
      TShape(Source).Top  := Y - (TShape(Source).Height div 2);
    except
      beep;
    end;
  end;
end;

procedure TfrmMain.P1EndDrag(Sender, Target: TObject; X, Y: Integer);
begin
  editing_poly := true;
  if TShape(Sender) =  P1 then begin
    edtPolyP1X.Value := p1.Left + (p1.Width div 2);
    edtPolyP1Y.Value := imgFrame.Height -(p1.Top + (p1.Height div 2));
  end else if TShape(Sender) =  P2 then begin
    edtPolyP2X.Value := p2.Left + (p2.Width div 2);
    edtPolyP2Y.Value := imgFrame.Height -(p2.Top + (p2.Height div 2));
  end else if TShape(Sender) =  P3 then begin
    edtPolyP3X.Value := p3.Left + (p3.Width div 2);
    edtPolyP3Y.Value := imgFrame.Height -(p3.Top + (p3.Height div 2));
  end else if TShape(Sender) =  P4 then begin
    edtPolyP4X.Value := p4.Left + (p4.Width div 2);
    edtPolyP4Y.Value := imgFrame.Height -(p4.Top + (p4.Height div 2));
  end;
  editing_poly := false;
  updateCurrentPoly;
  updateCurrentFrameGUI;
  ShowCurrentFramePolys;
end;

procedure TfrmMain.P1DragOver(Sender, Source: TObject; X, Y: Integer;
  State: TDragState; var Accept: Boolean);
begin
  Accept := true;
end;

procedure TfrmMain.updateCurrentPolyGUI;
var
  poly: TPoly;
begin
  poly := getCurrentPoly;
  if poly = nil then begin
    P1.Visible := false;
    P2.Visible := false;
    P3.Visible := false;
    P4.Visible := false;
    exit;
  end else begin
    P1.Visible := true;
    P2.Visible := true;
    P3.Visible := true;
    P4.Visible := true;
  end;

  P1.Left := poly.p1.X - (P1.Width  div 2);
  P1.Top  := imgFrame.Height-poly.p1.Y - (P1.Height div 2);
  P2.Left := poly.p2.X - (P2.Width  div 2);
  P2.Top  := imgFrame.Height- poly.p2.Y - (P2.Height div 2);
  P3.Left := poly.p3.X - (P3.Width  div 2);
  P3.Top  := imgFrame.Height- poly.p3.Y - (P3.Height div 2);
  P4.Left := poly.p4.X - (P4.Width  div 2);
  P4.Top  := imgFrame.Height- poly.p4.Y - (P4.Height div 2);
  P1.Visible := true;
  P2.Visible := true;
  P3.Visible := true;
  P4.Visible := true;
  ShowCurrentFramePolys;
end;

procedure TfrmMain.lstPolysClick(Sender: TObject);
begin
  updateCurrentPoly;
end;

procedure TfrmMain.Refresh1Click(Sender: TObject);
begin
  updateCurrentAction;
  updateCurrentFrame;
  updateCurrentPolyGUI;
  ShowCurrentFramePolys;

  updateCurrentTrajectory;

  lstInputsClick(Sender);
  lstTriggersClick(Sender);
end;

procedure TfrmMain.ShowCurrentFramePolys;
var
  frame: TFrame;
  poly:  TPoly;
  i : integer;
begin
  //First, draw all polys from this frame
  frame := getCurrentFrame;
  poly  := getCurrentPoly;
  //No frame selected
  if frame = nil then exit;
  //No image on frame
  if (imgFrame.Picture.Width=0) or (imgFrame.Picture.Height=0) then exit;
  //User don´t want we show polys
  if not chkShowPolys.Checked then exit;
  //Draw the polys
  for i := 0 to frame.polys.Count -1 do begin
    with imgFrame.Picture.Bitmap.Canvas do begin
      if TPoly(frame.polys.Items[i]) = poly then
        Pen.Color := selPolyColor
      else
        Pen.Color := PolyColor;
      MoveTo(
        TPoly(frame.polys.Items[i]).p1.X,
        imgFrame.Height-TPoly(frame.polys.Items[i]).p1.Y);
      LineTo(
        TPoly(frame.polys.Items[i]).p2.X,
        imgFrame.Height-TPoly(frame.polys.Items[i]).p2.Y);
      LineTo(
        TPoly(frame.polys.Items[i]).p3.X,
        imgFrame.Height-TPoly(frame.polys.Items[i]).p3.Y);
      LineTo(
        TPoly(frame.polys.Items[i]).p4.X,
        imgFrame.Height-TPoly(frame.polys.Items[i]).p4.Y);
      LineTo(
        TPoly(frame.polys.Items[i]).p1.X,
        imgFrame.Height-TPoly(frame.polys.Items[i]).p1.Y);
    end;
  end;

  //Adjust selected poly
  //updateCurrentPolyGUI;
end;


procedure TfrmMain.chkFrameCenterClick(Sender: TObject);
begin
  imgCenter.Visible := chkFrameCenter.Checked;
end;

procedure TfrmMain.chkShowPolysClick(Sender: TObject);
begin
  updateCurrentFrame;
  updateCurrentPolyGUI;
  ShowCurrentFramePolys;
end;

procedure TfrmMain.updateCurrentPoly;
var
  poly : TPoly;
begin
  if old_poly <> nil then begin
    try
      old_poly.trigger := edtPolyTrigger.Text;
      old_poly.priority := edtPolyPriority.Value;
      old_poly.p1.X := edtPolyP1X.Value;
      old_poly.p1.Y := edtPolyP1Y.Value;
      old_poly.p2.X := edtPolyP2X.Value;
      old_poly.p2.Y := edtPolyP2Y.Value;
      old_poly.p3.X := edtPolyP3X.Value;
      old_poly.p3.Y := edtPolyP3Y.Value;
      old_poly.p4.X := edtPolyP4X.Value;
      old_poly.p4.Y := edtPolyP4Y.Value;
    except
      beep;
      ShowMessage('Error updating poly properties!');
      exit;
    end;
  end;
  poly := getCurrentPoly;
  if poly=nil then exit;
  pgProperties.ActivePage := tabPoly;
  editing_poly := true;
  edtPolyTrigger.Text := poly.trigger;
  edtPolyPriority.Value := poly.priority;
  edtPolyP1X.Value := poly.p1.X;
  edtPolyP1Y.Value := poly.p1.Y;
  edtPolyP2X.Value := poly.p2.X;
  edtPolyP2Y.Value := poly.p2.Y;
  edtPolyP3X.Value := poly.p3.X;
  edtPolyP3Y.Value := poly.p3.Y;
  edtPolyP4X.Value := poly.p4.X;
  edtPolyP4Y.Value := poly.p4.Y;
  old_poly := poly;
  updateCurrentPolyGUI;
  editing_poly := False;
end;

procedure TfrmMain.edtPolyP1XChanged(Sender: TObject; NewValue: Integer);
begin
  if editing_poly then exit;
  updateCurrentPoly;
end;

procedure TfrmMain.ToolButton15Click(Sender: TObject);
var
  traj: TTrajectory;
  texto : string;
begin
  texto := 'Trajectory'+IntToStr(lstTrajectories.Items.Count);
  texto := inputbox('New trajectory', 'Please, type the name of the new trajectory:', texto);
  if (length(texto)=0) then exit;
  traj := TTrajectory.Create(texto);
  traj.width := imgTrajectory.Width;
  traj.Height := imgTrajectory.Height;
  traj.trigger := '';
  traj.nexttraj := '';
  lstTrajectories.ItemIndex:=lstTrajectories.Items.Add(texto);
  lstTrajectories.Items.Objects[lstTrajectories.ItemIndex] := traj;
end;

procedure TFrmMain.updateCurrentTrajectory;
var
  traj: TTrajectory;
  i, j: integer;
  trajpoint: TTrajPoint;
begin
  //Update current trajectory
  traj := getCurrentTrajectory;
  if traj=nil then begin
    lstPoints.Clear;
    exit;
  end;
  updateCurrentTrajPoint;
  j:=-1;
  if old_traj<>nil then begin
    old_traj.width := edtTrajWidth.Value;
    old_traj.Height := edtTrajHeight.Value;
    old_traj.trigger := trim(edtTrajTrigger.Text);
    old_traj.nexttraj := trim(edtNextTraj.Text);
    if lstPoints.ItemIndex>=0 then
      j:= lstPoints.ItemIndex;
  end;
  edtTrajWidth.Value := traj.width;
  edtTrajHeight.Value := traj.Height;
  edtTrajTrigger.Text := traj.trigger;
  edtNextTraj.Text := traj.nextTraj;
  lstPoints.Clear;
  for i := 0 to traj.points.Count-1 do  begin
    trajpoint := TTrajPoint(traj.points.Items[i]);
    lstPoints.ItemIndex := lstPoints.Items.Add(trajpoint.caption);
    lstPoints.Items.Objects[lstPoints.ItemIndex] := trajpoint;
  end;
  if (j>=0) and (lstPoints.Items.Count >0) then
    lstPoints.ItemIndex := j;
  old_traj := traj;

  drawTrajectoryPoints;

end;

function  TFrmMain.getCurrentTrajectory: TTrajectory;
begin
  if lstTrajectories.ItemIndex <0 then
    Result := nil
  else
    Result := TTrajectory(lstTrajectories.Items.Objects[lstTrajectories.ItemIndex]);
end;

procedure TFrmMain.updateCurrentTrajPoint;
var
  trajPoint: TTrajPoint;
begin
  trajPoint := getCurrentTrajPoint;
  if trajPoint=nil then exit;
  if old_trajpoint<>nil then begin
    old_trajpoint.p.X := edtTrajCX.Value;
    old_trajpoint.p.Y := edtTrajCY.Value;
    old_trajpoint.time := edtTrajTime.Value;
    old_trajpoint.AFrames := edtTrajAFrames.Value;
  end;
  edtTrajCX.Value := trajPoint.p.X;
  edtTrajCY.Value := trajPoint.p.Y;
  edtTrajTime.Value := trajPoint.time;
  edtTrajAFrames.Value := trajPoint.AFrames;
  old_trajpoint := trajPoint;
end;

function  TFrmMain.getCurrentTrajPoint: TTrajPoint;
begin
  if getCurrentTrajectory=nil then begin
    Result := nil;
    exit;
  end;
  if lstPoints.ItemIndex <0 then
    Result := nil
  else
    Result := TTrajPoint(lstPoints.Items.Objects[lstPoints.ItemIndex]);
end;

procedure TfrmMain.ToolButton17Click(Sender: TObject);
var
  traj: TTrajectory;
  p: TTrajPoint;
  texto : string;
begin
  traj := getCurrentTrajectory;
  if traj=nil then begin
    beep;
    ShowMessage('Please, select a trajectory first');
    exit;
  end;
  texto := 'P'+IntToStr(lstPoints.Items.Count);
  texto := inputbox('New Point', 'Please, type the name of the new Point:', texto);
  if (length(texto)=0) then exit;
  p := TTrajPoint.Create(texto);
  p.p.X := imgTrajectory.Width div 2;
  p.p.Y := imgTrajectory.Height div 2;
  edtTrajCX.Value := p.p.X;
  edtTrajCY.Value := p.p.Y;
  traj.points.Add(p);
  lstPoints.ItemIndex:=lstPoints.Items.Add(texto);
  lstPoints.Items.Objects[lstPoints.ItemIndex] := p;
  old_trajpoint := p;
  drawTrajectoryPoints;
  updateCurrentTrajPoint;
end;


procedure TfrmMain.lstTrajectoriesClick(Sender: TObject);
begin
  updateCurrentTrajectory;
  pgTrajs.ActivePage := tabTraj;
end;

procedure TfrmMain.lstPointsClick(Sender: TObject);
begin
  updateCurrentTrajPoint;
  drawTrajectoryPoints;
  pgTrajs.ActivePage := tabTrajPoint;
end;

procedure TfrmMain.edtTrajCXChanged(Sender: TObject; NewValue: Integer);
begin
  PTraj.Left := edtTrajCX.Value - (PTraj.Width div 2) - scrollTraj.HorzScrollBar.Position;
end;

procedure TfrmMain.edtTrajCYChanged(Sender: TObject; NewValue: Integer);
begin
  PTraj.Top  := imgTrajectory.Height- edtTrajCY.Value - (PTraj.Height div 2) - scrollTraj.VertScrollBar.Position;
end;

procedure TfrmMain.PTrajDragOver(Sender, Source: TObject; X, Y: Integer;
  State: TDragState; var Accept: Boolean);
begin
  Accept := true;
  pgTrajs.ActivePage := tabTrajPoint;
end;

procedure TfrmMain.PTrajEndDrag(Sender, Target: TObject; X, Y: Integer);
begin
  edtTrajCX.Value := ptraj.Left + (ptraj.Width div 2) + scrollTraj.HorzScrollBar.Position;;
  edtTrajCY.Value := imgTrajectory.Height -(ptraj.Top + (ptraj.Height div 2)) + scrollTraj.VertScrollBar.Position;;
  updateCurrentTrajPoint;
  updateCurrentTrajectory;
end;

procedure TfrmMain.imgTrajectoryDragOver(Sender, Source: TObject; X,
  Y: Integer; State: TDragState; var Accept: Boolean);
begin
  Accept := true;
  if state = dsDragMove	 then begin
    try
      TShape(Source).Left := X - (TShape(Source).Width div 2) - scrollTraj.HorzScrollBar.Position;
      TShape(Source).Top  := Y - (TShape(Source).Height div 2) - scrollTraj.VertScrollBar.Position;
    except
      beep;
    end;
  end;
end;

procedure TfrmMain.edtTrajWidthChanged(Sender: TObject; NewValue: Integer);
var
  traj: TTrajectory;
begin
  traj := getCurrentTrajectory;
  if traj=nil then exit;
  traj.width := edtTrajWidth.Value;
  imgTrajectory.Width := edtTrajWidth.Value;
  imgTrajectory.Picture.Bitmap.Width := edtTrajWidth.Value;
end;

procedure TfrmMain.edtTrajHeightChanged(Sender: TObject;
  NewValue: Integer);
var
  traj: TTrajectory;
begin
  traj := getCurrentTrajectory;
  if traj=nil then exit;
  traj.height := edtTrajHeight.Value;
  imgTrajectory.Height := edtTrajHeight.Value;
  imgTrajectory.Picture.Bitmap.Height := edtTrajHeight.Value;
end;

procedure TFrmMain.drawTrajectoryPoints;
var
  traj: TTrajectory;
  i: integer;
  trajpoint: TTrajPoint;
begin
  //Update current trajectory
  traj := getCurrentTrajectory;
  if traj=nil then begin
    lstPoints.Clear;
  end;

  //Draw points
  trajpoint := getCurrentTrajPoint;
  with imgTrajectory.Canvas do begin
    Brush.Style := bsSolid;
    FillRect(
      Rect(0,0,imgTrajectory.Width, imgTrajectory.Height));
    if traj.points.Count <=0 then exit;
    MoveTo(
      TTrajPoint(traj.points.Items[0]).p.X,
      imgTrajectory.Height-TTrajPoint(traj.points.Items[0]).p.Y);
    imgTrajectory.Canvas.Ellipse(
        Rect(TTrajPoint(traj.points.Items[0]).p.X - (PTraj.Width div 2),
        imgTrajectory.Height-TTrajPoint(traj.points.Items[0]).p.Y - (PTraj.Height div 2),
        TTrajPoint(traj.points.Items[0]).p.X + (PTraj.Width div 2),
        imgTrajectory.Height-TTrajPoint(traj.points.Items[0]).p.Y + (PTraj.Height div 2)
        ));
    for i := 1 to traj.points.Count-1 do begin
      if (trajPoint = TTrajPoint(traj.points.Items[i])) or
          (trajPoint = TTrajPoint(traj.points.Items[i-1])) then begin
        Pen.Color := clBlue;
      end else begin
        Pen.Color := clBlack;
      end;
      LineTo(
        TTrajPoint(traj.points.Items[i]).p.X,
        imgTrajectory.Height-TTrajPoint(traj.points.Items[i]).p.Y);
      Brush.Style := bsDiagCross;
      imgTrajectory.Canvas.Ellipse(
        Rect(TTrajPoint(traj.points.Items[i]).p.X - (PTraj.Width div 2),
        imgTrajectory.Height-TTrajPoint(traj.points.Items[i]).p.Y - (PTraj.Height div 2),
        TTrajPoint(traj.points.Items[i]).p.X + (PTraj.Width div 2),
        imgTrajectory.Height-TTrajPoint(traj.points.Items[i]).p.Y + (PTraj.Height div 2)
        ));
    end;
  end;
end;

procedure TfrmMain.ToolButton11Click(Sender: TObject);
var
  texto : string;
begin
  texto := 'State'+IntToStr(lstStates.Items.Count);
  texto := inputbox('New State', 'Please, type the name of the new state:', texto);
  if (length(texto)=0) then exit;
  lstStates.Items.Add(texto);
end;

procedure TfrmMain.ToolButton12Click(Sender: TObject);
begin
  if lstStates.ItemIndex <0 then exit;
  lstStates.Items.Delete(lstStates.ItemIndex);
end;

procedure TfrmMain.ToolButton13Click(Sender: TObject);
var
  texto : string;
  trigger: TTrigger;
begin
  texto := 'Trigger'+IntToStr(lstTriggers.Items.Count);
  texto := inputbox('New trigger', 'Please, type the name of the new trigger:', texto);
  if (length(texto)=0) then exit;
  if old_trigger <> nil then begin
    old_trigger.text := edtTrigger.Lines.Text;
  end;
  trigger := TTrigger.Create(texto);
  old_trigger := trigger;
  lstTriggers.ItemIndex := lstTriggers.Items.Add(texto);
  lstTriggers.Items.Objects[lstTriggers.ItemIndex] := trigger;
end;

procedure TfrmMain.ToolButton14Click(Sender: TObject);
begin
  if lstTriggers.ItemIndex <0 then exit;
  lstTriggers.Items.Delete(lstTriggers.ItemIndex);
end;

procedure TfrmMain.lstTriggersClick(Sender: TObject);
var
  trigger: TTrigger;
begin
  if lstTriggers.ItemIndex <0 then exit;
  if old_trigger <> nil then begin
    old_trigger.text := edtTrigger.Lines.Text;
  end;
  trigger := TTrigger(lstTriggers.Items.Objects[lstTriggers.ItemIndex]);
  edtTrigger.Lines.Text := trigger.text;
  old_trigger := trigger;
  lbTriggerName.Caption := ' int '+trigger.caption+'(trigger_data *data) {';
end;

procedure TfrmMain.grdInputsSetEditText(Sender: TObject; ACol,
  ARow: Integer; const Value: WideString);
begin
  if ACol < 9 then begin
    if (value='1') or (uppercase(value)='T') or (uppercase(value)='TRUE') then
      grdInputs.Cells[ACol, ARow] := 'TRUE'
    else
      grdInputs.Cells[ACol, ARow] := 'FALSE';
  end else begin
    try
      if StrToInt(grdInputs.Cells[ACol, ARow])<0 then
        grdInputs.Cells[ACol, ARow]:='0';
    except
      grdInputs.Cells[ACol, ARow]:='0';
    end;
  end;
end;

procedure TFrmMain.resetCurrentInput;
var
  i, j: integer;
begin
  grdInputs.Cells[1, 0] := 'LEFT';
  grdInputs.Cells[2, 0] := 'UP';
  grdInputs.Cells[3, 0] := 'RIGHT';
  grdInputs.Cells[4, 0] := 'DOWN';
  grdInputs.Cells[5, 0] := 'A';
  grdInputs.Cells[6, 0] := 'B';
  grdInputs.Cells[7, 0] := 'C';
  grdInputs.Cells[8, 0] := 'D';
  grdInputs.Cells[9, 0] := 'MinDur';
  grdInputs.Cells[10, 0] := 'MaxDur';
  grdInputs.ColWidths[9] := grdInputs.Canvas.TextWidth('MinDur');
  grdInputs.ColWidths[10] := grdInputs.Canvas.TextWidth('MaxDur');
  for j := 1 to grdInputs.RowCount-1 do begin
      grdInputs.Cells[0, j] := IntToStr(j);
    end;
  for i := 1 to 8 do begin
    for j := 1 to grdInputs.RowCount-1 do begin
      grdInputs.Cells[i, j] := 'FALSE';
    end;
  end;
  for j := 1 to grdInputs.RowCount-1 do begin
    grdInputs.Cells[9, j] := '0';
  end;
  for j := 1 to grdInputs.RowCount-1 do begin
    grdInputs.Cells[10, j] := '2';
  end;
end;

procedure TfrmMain.grdInputsDrawCell(Sender: TObject; ACol, ARow: Integer;
  Rect: TRect; State: TGridDrawState);
begin
  if (ARow>0) and (ACol<9) then begin
    if grdInputs.Cells[ACol, ARow]='TRUE' then begin
      grdInputs.Canvas.Font.Color := clBlue;
      grdInputs.Canvas.Brush.Color := clWhite;
    end else begin
      grdInputs.Canvas.Font.Color := clRed;
      grdInputs.Canvas.Brush.Color := clSilver;
    end;
  end else begin
    grdInputs.Canvas.Brush.Color := clWhite;
    if grdInputs.Cells[ACol, ARow]='0' then
      grdInputs.Canvas.Font.Color := clGray
    else
      grdInputs.Canvas.Font.Color := clBlack;
  end;
  grdInputs.Canvas.FillRect(Rect);
  grdInputs.Canvas.TextOut(rect.Left, rect.Top, grdInputs.Cells[ACol, ARow]);
  if (gdFocused in State) then
    grdInputs.Canvas.DrawFocusRect(Rect);
end;

procedure TfrmMain.ToolButton7Click(Sender: TObject);
var
  texto : string;
  input: TInput;
  i, j: integer;
begin
  texto := 'Input'+IntToStr(lstInputs.Items.Count);
  texto := inputbox('New input', 'Please, type the name of the new input:', texto);
  if (length(texto)=0) then exit;
  if old_input <> nil then begin
    for i := 1 to 10 do
      for j := 1 to 16 do
        old_input.props[i,j] := grdInputs.Cells[i,j];
  end;
  input := TInput.Create(texto);
  old_input := input;
  lstInputs.ItemIndex := lstInputs.Items.Add(texto);
  lstInputs.Items.Objects[lstInputs.ItemIndex] := input;
end;

procedure TfrmMain.ToolButton8Click(Sender: TObject);
begin
  if lstInputs.ItemIndex <0 then exit;
  lstInputs.Items.Delete(lstInputs.ItemIndex);
end;

procedure TfrmMain.lstInputsClick(Sender: TObject);
var
  input: TInput;
  i, j: integer;
begin
  if lstInputs.ItemIndex <0 then exit;
  if old_input <> nil then begin
    for i := 1 to 10 do
      for j := 1 to 16 do
        old_input.props[i,j] := grdInputs.Cells[i,j];
    old_input.trigger := edtInputTrigger.Text;
    old_input.trigger2 := edtInputTrigger2.Text;
  end;
  input := TInput(lstInputs.Items.Objects[lstInputs.ItemIndex]);
  for i := 1 to 10 do
      for j := 1 to 16 do
        grdInputs.Cells[i,j] := input.props[i,j];
  edtInputTrigger.Text := input.trigger;
  edtInputTrigger2.Text := input.trigger2;
  old_input := input;
  grdInputs.Refresh;
end;

procedure TfrmMain.ToolButton18Click(Sender: TObject);
var
  trajPoint: TTrajPoint;
  traj: TTrajectory;
begin
  traj := getCurrentTrajectory;
  if traj=nil then exit;
  trajPoint := getCurrentTrajPoint;
  if trajPoint=nil then exit;
  if old_trajpoint = trajpoint then
    old_trajpoint := nil;
  traj.points.Delete(traj.points.IndexOf(trajPoint));
  lstPoints.Items.Delete(lstPoints.ItemIndex);
  drawTrajectoryPoints;
end;

procedure TfrmMain.edtTrajTriggerChange(Sender: TObject);
var
  traj: TTrajectory;
begin
  traj := getCurrentTrajectory;
  if traj=nil then exit;
  traj.trigger := trim(edtTrajTrigger.Text);
end;

procedure TfrmMain.ToolButton16Click(Sender: TObject);
begin
  if lstTrajectories.ItemIndex <0 then exit;
  lstTrajectories.Items.Delete(lstTrajectories.ItemIndex);
end;

procedure TfrmMain.ToolButton2Click(Sender: TObject);
begin
  if lstActions.ItemIndex <0 then exit;
  lstActions.Items.Delete(lstActions.ItemIndex);
end;

procedure TfrmMain.ToolButton6Click(Sender: TObject);
var
  frame: TFrame;
  poly:  TPoly;
begin
  frame := getCurrentFrame;
  if frame=nil then begin
    ShowMessage('Please select a frame first!');
    exit;
  end;
  poly := getCurrentPoly;
  if poly=nil then begin
    ShowMessage('Please select a poly first!');
    exit;
  end;
  frame.polys.Delete(frame.polys.IndexOf(poly));
  lstPolys.Items.Delete(lstPolys.ItemIndex);
end;

procedure TfrmMain.ToolButton4Click(Sender: TObject);
var
  frame: TFrame;
  action:  TAction;
begin
  action := getCurrentAction;
  if action=nil then begin
    ShowMessage('Please select a action first!');
    exit;
  end;
  frame := getCurrentFrame;
  if frame=nil then begin
    ShowMessage('Please select a frame first!');
    exit;
  end;
  action.frames.Delete(action.frames.IndexOf(frame));
  lstFrames.Items.Delete(lstFrames.ItemIndex);
end;

procedure TfrmMain.Button3Click(Sender: TObject);
var
  i:      integer;
  action: TAction;
  frame : TFrame;
begin
  action := getCurrentAction;
  if action=nil then begin
    ShowMessage('Please, select an action first!');
    exit;
  end;
  if action.frames.Count<=0 then begin
    ShowMessage('There are no frames to show!');
    exit;
  end;
  updateCurrentFrame;
  if edtBaseFolder.Text[length(edtBaseFolder.Text)]<>'\' then
        edtBaseFolder.Text := edtBaseFolder.Text + '\';
  for i := 0 to action.frames.Count -1 do begin
    frame := TFrame(action.frames.Items[i]);
    frmTestAction.bmps[i] := TBitmap.Create;
    try
      frmTestAction.bmps[i].LoadFromFile(edtBaseFolder.Text+'images\'+frame.ImageFile);
    except
      frmTestAction.bmps[i].Destroy;
      frmTestAction.bmps[i]:=nil;
    end;
    Inc(frmTestAction.num_bmps);
  end;
  frmTestAction.ShowModal;
end;

procedure TfrmMain.btnSaveFileClick(Sender: TObject);
var
  mdoc: TXMLDocument;
  doc:  IXMLNode;
  nactions, ntrajectories, nstates, ninputs, ntriggers: IXMLNode;
  action:TAction; frame: TFrame; poly: TPoly;
  naction, nframe, npoly: IXMLNode;
  traj: TTrajectory; point: TTrajPoint;
  ntraj, npoint: IXMLNode;
  input: TInput;
  ninput, ninputset: IXMLNode;
  trigger: TTrigger;
  ntrigger: IXMLNode;
  i, j, k: integer;
  temp, temp2: TStringList;
begin
  mdoc := TXMLDocument.Create(self);
  Refresh1Click(Sender);
  mdoc.Active := true;
  doc  := mdoc.AddChild('sprite');
  try
    if edtBaseFolder.Text[length(edtBaseFolder.Text)]<>'\' then
      edtBaseFolder.Text := edtBaseFolder.Text + '\';
    nactions      := doc.AddChild('Actions');
    ntrajectories := doc.AddChild('Trajectories');
    nstates       := doc.AddChild('States');
    ninputs       := doc.AddChild('Inputs');
    ntriggers     := doc.AddChild('Triggers');
    for i := 0 to lstActions.Items.Count -1 do begin
      action := TAction(lstActions.Items.Objects[i]);
      naction := nactions.AddChild('ACTION');
      naction.Attributes['name'] := action.caption;
      naction.Attributes['nextaction'] := action.nextAction;
      naction.Attributes['soundfile'] := action.soundfile;
      naction.Attributes['Trigger'] := action.trigger;
      for j := 0 to action.frames.Count-1 do begin
        frame := TFrame(action.frames.Items[j]);
        nframe:= naction.AddChild('FRAME');
        nframe.Attributes['name'] := frame.caption;
        nframe.Attributes['state'] := frame.State;
        nframe.Attributes['imagefile'] := frame.ImageFile;
        nframe.Attributes['centerx'] := frame.Center.X;
        nframe.Attributes['centery'] := frame.Center.Y;
        for k := 0 to frame.polys.Count-1 do begin
          poly := TPoly(frame.polys.Items[k]);
          npoly := nframe.AddChild('POLY');
          npoly.Attributes['name'] := poly.caption;
          npoly.Attributes['trigger'] := poly.trigger;
          npoly.Attributes['priority'] := poly.priority;
          npoly.Attributes['p1x'] := poly.p1.X;
          npoly.Attributes['p1y'] := poly.p1.Y;
          npoly.Attributes['p2x'] := poly.p2.X;
          npoly.Attributes['p2y'] := poly.p2.Y;
          npoly.Attributes['p3x'] := poly.p3.X;
          npoly.Attributes['p3y'] := poly.p3.Y;
          npoly.Attributes['p4x'] := poly.p4.X;
          npoly.Attributes['p4y'] := poly.p4.Y;
        end;
      end;
    end;
    for i := 0 to lstTrajectories.Items.Count -1 do begin
      traj := TTrajectory(lstTrajectories.Items.Objects[i]);
      ntraj := ntrajectories.AddChild('TRAJECTORY');
      ntraj.Attributes['name'] := traj.caption;
      ntraj.Attributes['trigger'] := traj.trigger;
      ntraj.Attributes['nexttraj'] := traj.nexttraj;
      ntraj.Attributes['width'] := traj.width;
      ntraj.Attributes['height'] := traj.height;
      for j := 0 to traj.points.Count-1 do begin
        point := TTrajPoint(traj.points.Items[j]);
        npoint:= ntraj.AddChild('POINT');
        npoint.Attributes['name'] := point.caption;
        npoint.Attributes['aframes'] := point.AFrames;
        npoint.Attributes['time'] := point.time;
        npoint.Attributes['x'] := point.p.X;
        npoint.Attributes['y'] := point.p.Y;
      end;
    end;
    temp := TStringList.Create;
    temp2 := TStringList.Create;
    temp.Add('#include <gftriggerc.h>'); 
    for i := 0 to lstTriggers.Items.Count -1 do begin
      trigger := TTrigger(lstTriggers.Items.Objects[i]);
      ntrigger := ntriggers.AddChild('TRIGGER');
      ntrigger.Attributes['name'] := trigger.caption;
      ntrigger.Text := trigger.text;
      temp2.Text := trigger.text;
      temp2.SaveToFile(trigger.caption+'.c');
      temp.Add('int '+trigger.caption+'(trigger_data *data) {');
      temp.Add(trigger.text);
      temp.Add('}');
      temp.Add('');      
    end;
    temp.SaveToFile('triggers.c');
    temp.Destroy;
    temp2.Destroy;
    for i := 0 to lstStates.Items.Count -1 do begin
      nstates.AddChild('STATE').Attributes['name']:=lstStates.Items.Strings[i];
    end;
    for i := 0 to lstInputs.Items.Count -1 do begin
      input := TInput(lstInputs.Items.Objects[i]);
      ninput := ninputs.AddChild('INPUT');
      ninput.Attributes['name'] := input.caption;
      ninput.Attributes['trigger'] := input.trigger;
      ninput.Attributes['triggerRelease'] := input.trigger2;
      //props: array[1..10,1..16] of string;
      for j := 1 to 16 do begin
        ninputset:= ninput.AddChild('INPUTSET');
        ninputset.Attributes['LEFT'] := input.props[1, j];
        ninputset.Attributes['UP'] := input.props[2, j];
        ninputset.Attributes['RIGHT'] := input.props[3, j];
        ninputset.Attributes['DOWN'] := input.props[4, j];
        ninputset.Attributes['A'] := input.props[5, j];
        ninputset.Attributes['B'] := input.props[6, j];
        ninputset.Attributes['C'] := input.props[7, j];
        ninputset.Attributes['D'] := input.props[8, j];
        ninputset.Attributes['mindur'] := input.props[9, j];
        ninputset.Attributes['maxdur'] := input.props[10, j];
      end;
    end;
    mdoc.SaveToFile(edtBaseFolder.Text+'sprite.xml');
    ShowMessage('File "'+edtBaseFolder.Text+'sprite.xml" saved succesfully');
  except
    beep;
    ShowMessage('Unable to save file "'+edtBaseFolder.Text+'sprite.xml"');
  end;
  mdoc.Destroy;
end;

procedure TfrmMain.btnLoadFileClick(Sender: TObject);
var
  mdoc: TXMLDocument;
  doc:  IXMLNode;
  nactions, ntrajectories, nstates, ninputs, ntriggers: IXMLNode;
  action:TAction; frame: TFrame; poly: TPoly;
  naction, nframe, npoly: IXMLNode;
  traj: TTrajectory; point: TTrajPoint;
  ntraj, npoint: IXMLNode;
  input: TInput;
  ninput, ninputset: IXMLNode;
  trigger: TTrigger;
  ntrigger: IXMLNode;
  i, j, k: integer;
  temp: TStringList;
begin
  mdoc := TXMLDocument.Create(self);
  if doAttrNull	in mdoc.Options then
    mdoc.Options := mdoc.Options - [doAttrNull];
  lstInputs.Clear;
  lstActions.Clear;
  lstTrajectories.Clear;
  lstTriggers.Clear;
  lstStates.Clear;
  try
    if edtBaseFolder.Text[length(edtBaseFolder.Text)]<>'\' then
      edtBaseFolder.Text := edtBaseFolder.Text + '\';
    mdoc.LoadFromFile(edtBaseFolder.Text+'sprite.xml');
    doc := mdoc.ChildNodes.FindNode('sprite');
    nactions      := doc.ChildNodes.FindNode('Actions');
    ntrajectories := doc.ChildNodes.FindNode('Trajectories');
    nstates       := doc.ChildNodes.FindNode('States');
    ninputs       := doc.ChildNodes.FindNode('Inputs');
    ntriggers     := doc.ChildNodes.FindNode('Triggers');
    lstActions.Clear;
    for i := 0 to nactions.ChildNodes.Count -1 do begin
      naction := nactions.ChildNodes.Get(i);
      action := TAction.Create(naction.Attributes['name']);
      lstActions.items.objects[lstActions.Items.Add(action.caption)]:=action;
      action.nextAction := naction.Attributes['nextaction'];
      action.soundfile := naction.Attributes['soundfile'];
      action.trigger := naction.Attributes['Trigger'];
      for j := 0 to naction.ChildNodes.Count -1 do begin
        nframe := naction.ChildNodes.Get(j);
        frame := TFrame.Create(nframe.Attributes['name']);
        action.frames.Add(frame);
        frame.State := nframe.Attributes['state'];
        frame.ImageFile := nframe.Attributes['imagefile'];
        frame.Center.X := nframe.Attributes['centerx'];
        frame.Center.Y := nframe.Attributes['centery'];
        for k := 0 to nframe.ChildNodes.Count -1 do begin
          npoly := nframe.ChildNodes.Get(k);
          poly := TPoly.Create(npoly.Attributes['name']);
          frame.polys.Add(poly);
          poly.trigger := npoly.Attributes['trigger'];
          poly.priority := npoly.Attributes['priority'];
          poly.p1.X := npoly.Attributes['p1x'];
          poly.p1.Y := npoly.Attributes['p1y'];
          poly.p2.X := npoly.Attributes['p2x'];
          poly.p2.Y := npoly.Attributes['p2y'];
          poly.p3.X := npoly.Attributes['p3x'];
          poly.p3.Y := npoly.Attributes['p3y'];
          poly.p4.X := npoly.Attributes['p4x'];
          poly.p4.Y := npoly.Attributes['p4y'];
        end;
      end;
    end;
    lstTrajectories.Clear;
    for i := 0 to ntrajectories.ChildNodes.Count -1 do begin
      ntraj := ntrajectories.ChildNodes.Get(i);
      traj := TTrajectory.Create(ntraj.Attributes['name']);
      lstTrajectories.items.objects[lstTrajectories.Items.Add(traj.caption)]:=traj;
      traj.trigger := ntraj.Attributes['trigger'];
      traj.nexttraj := ntraj.Attributes['nexttraj'];
      traj.width := ntraj.Attributes['width'];
      traj.height := ntraj.Attributes['height'];
      for j := 0 to ntraj.ChildNodes.Count -1 do begin
        npoint := ntraj.ChildNodes.Get(j);
        point := TTrajPoint.Create(npoint.Attributes['name']);
        traj.points.Add(point);
        point.AFrames := npoint.Attributes['aframes'];
        point.time := npoint.Attributes['time'];
        point.p.X := npoint.Attributes['x'];
        point.p.Y := npoint.Attributes['y'];
      end;
    end;

    temp := TStringList.Create;
    for i := 0 to ntriggers.ChildNodes.Count -1 do begin
      ntrigger := ntriggers.ChildNodes.Get(i);
      trigger := TTrigger.Create(ntrigger.Attributes['name']);
      trigger.text := ntrigger.Text;
      //If file exists, overwrite trigger text using it
      try
        temp.LoadFromFile(trigger.caption+'.c');
        trigger.text := temp.Text;
      except
        ShowMessage ('Warning: Couldn´t load trigger from file "'+trigger.caption+'.c"!');
      end;
      lstTriggers.items.objects[lstTriggers.Items.Add(trigger.caption)]:=trigger;
    end;
    temp.Destroy;
    for i := 0 to nstates.ChildNodes.Count -1 do begin
      lstStates.Items.Add(nstates.ChildNodes.Get(i).Attributes['name']);
    end;

    for i := 0 to ninputs.ChildNodes.Count -1 do begin
      ninput := ninputs.ChildNodes.Get(i);
      input := TInput.Create(ninput.Attributes['name']);
      input.trigger := ninput.Attributes['trigger'];
      input.trigger2 := ninput.Attributes['triggerRelease'];
      lstInputs.items.objects[lstInputs.Items.Add(input.caption)]:=input;
      //props: array[1..10,1..16] of string;
      for j := 1 to ninput.ChildNodes.Count do begin
        ninputset := ninput.ChildNodes.Get(j-1);
        if j>16 then break;
        input.props[1, j] := ninputset.Attributes['LEFT'];
        input.props[2, j] := ninputset.Attributes['UP'];
        input.props[3, j] := ninputset.Attributes['RIGHT'];
        input.props[4, j] := ninputset.Attributes['DOWN'];
        input.props[5, j] := ninputset.Attributes['A'];
        input.props[6, j] := ninputset.Attributes['B'];
        input.props[7, j] := ninputset.Attributes['C'];
        input.props[8, j] := ninputset.Attributes['D'];
        input.props[9, j] := ninputset.Attributes['mindur'];
        input.props[10, j] := ninputset.Attributes['maxdur'];
      end;
    end;
    
    Refresh1Click(Sender);
    ShowMessage('File "'+edtBaseFolder.Text+'sprite.xml" loaded succesfully');
  except
    beep;
    ShowMessage('Unable to load file "'+edtBaseFolder.Text+'sprite.xml"');
  end;
  mdoc.Destroy;
end;

procedure TfrmMain.edtNextTrajChange(Sender: TObject);
var
  traj: TTrajectory;
begin
  traj := getCurrentTrajectory;
  if traj=nil then exit;
  traj.nexttraj := trim(edtNextTraj.Text);
end;

procedure TfrmMain.lstActionsDblClick(Sender: TObject);
var
  action : TAction;
begin
  action := getCurrentAction;
  if (action = nil) then exit;
  action.caption := inputbox('Rename', 'Enter new name', action.caption);
  if (action.caption='') then exit;
  lstActions.Items.Strings[lstActions.ItemIndex] := action.caption;
end;

procedure TfrmMain.lstTrajectoriesDblClick(Sender: TObject);
var
  item : TTrajectory;
begin
  item := getCurrentTrajectory;
  if (item = nil) then exit;
  item.caption := inputbox('Rename', 'Enter new name', item.caption);
  if (item.caption='') then exit;
  lstTrajectories.Items.Strings[lstTrajectories.ItemIndex] := item.caption;
end;

procedure TfrmMain.lstInputsDblClick(Sender: TObject);
var
  item : TInput;
begin
  if lstInputs.ItemIndex <0 then exit;
  item := TInput(lstInputs.Items.Objects[lstInputs.ItemIndex]);
  if (item = nil) then exit;
  item.caption := inputbox('Rename', 'Enter new name', item.caption);
  if (item.caption='') then exit;
  lstInputs.Items.Strings[lstInputs.ItemIndex] := item.caption;
end;

procedure TfrmMain.lstTriggersDblClick(Sender: TObject);
var
  item: TTrigger;
begin
  if lstTriggers.ItemIndex <0 then exit;
  item := TTrigger(lstTriggers.Items.Objects[lstTriggers.ItemIndex]);
  if (item = nil) then exit;
  item.caption := inputbox('Rename', 'Enter new name', item.caption);
  if (item.caption='') then exit;
  lstTriggers.Items.Strings[lstTriggers.ItemIndex] := item.caption;
end;

end.



