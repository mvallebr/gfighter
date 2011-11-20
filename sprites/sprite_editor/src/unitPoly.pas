unit unitPoly;

interface

uses Types;

type
  TPoly = class(TObject)
  private
    { Private declarations }
  public
    { Public declarations }
    p1, p2, p3, p4: TPoint;
    priority: integer;
    trigger:  string;
    caption : String;
    constructor Create(ncaption: String);
  end;

implementation


constructor TPoly.Create(ncaption: String);
begin
  inherited Create;
  caption := ncaption;
  priority := 0;
  trigger := '';
  p1.X := 0;
  p1.Y := 0;
  p2.X := 0;
  p2.Y := 0;
  p3.X := 0;
  p3.Y := 0;
  p4.X := 0;
  p4.Y := 0;
end;

end.
