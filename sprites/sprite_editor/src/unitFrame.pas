unit unitFrame;

interface

uses classes, Types;

type
  TFrame = class(TObject)
  private
    { Private declarations }
  public
    { Public declarations }
    polys: TList;
    caption:  String;

    State:      String;
    ImageFile:  String;
    Center:     TPoint;

    constructor Create(ncaption: String);
  end;

implementation


constructor TFrame.Create(ncaption: String);
begin
  inherited Create;
  Caption := ncaption;
  polys := TList.Create;
  State:='';
  ImageFile:='';
  Center.X := 0;
  Center.Y := 0;
end;

end.
