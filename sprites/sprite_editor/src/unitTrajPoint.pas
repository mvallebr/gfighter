unit unitTrajPoint;


interface

uses classes, types, QExtCtrls;

type
  TTrajPoint = class(TObject)
  private
    { Private declarations }
  public
    { Public declarations }
    p: TPoint;
    caption: string;
    AFrames:  integer; // Number of action frames to be showed from this to next point
    time:     integer; // Time, in frames, to next point 
    constructor Create(ncaption: String);
  end;

implementation

constructor TTrajPoint.Create(ncaption: String);
begin
  inherited Create;
  caption := ncaption;
  p.X := 0;
  p.Y := 0;
  AFrames:=1;
  time :=1;
end;


end.
