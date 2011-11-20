unit formTestAction;

interface

uses
  SysUtils, Types, Classes, Variants, QTypes, QGraphics, QControls, QForms, 
  QDialogs, QStdCtrls, QComCtrls, QExtCtrls;

type
  TfrmTestAction = class(TForm)
    ScrollBox1: TScrollBox;
    Panel1: TPanel;
    edtSpeed: TSpinEdit;
    Label4: TLabel;
    imgAnimation: TImage;
    Timer: TTimer;
    procedure edtSpeedChanged(Sender: TObject; NewValue: Integer);
    procedure TimerTimer(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
  private
    { Private declarations }
  public
    { Public declarations }
    num_bmps: integer;
    current_frame:  integer;
    bmps: array[0..1000] of TBitmap;
  end;

var
  frmTestAction: TfrmTestAction;

implementation

{$R *.xfm}

procedure TfrmTestAction.edtSpeedChanged(Sender: TObject;
  NewValue: Integer);
begin
  Timer.Interval := (edtSpeed.Value*1000) div 60;
end;

procedure TfrmTestAction.TimerTimer(Sender: TObject);
begin
  if not frmTestAction.Visible then exit;
  Inc(current_frame);
  if current_frame>=num_bmps then begin
    current_frame := -1;
    exit;
  end;
  if bmps[current_frame] <> nil then
    imgAnimation.Picture.Assign(bmps[current_frame]);
end;

procedure TfrmTestAction.FormCreate(Sender: TObject);
var
  i: integer;
begin
  num_bmps := 0;
  current_frame := -1;
  for i := 0 to 1000 do
    bmps[i] := nil;
end;

procedure TfrmTestAction.FormClose(Sender: TObject;
  var Action: TCloseAction);
var
  i: integer;
begin
  for i := 0 to num_bmps-1 do begin
    if bmps[i]<>nil then
      bmps[i].Destroy;
    bmps[i]:=nil;
  end;
  num_bmps:=0;
  current_frame:=-1;
end;

end.
