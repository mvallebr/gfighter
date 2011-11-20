unit unitSprite;

interface

uses
  classes,
  unitAction, unitFrame, unitInput, unitPoly, unitTrajectory;

type
  TSprite = class(TObject)
  private
    { Private declarations }
  public
    { Public declarations }
    actions: TList;
    constructor Create;
  end;

implementation


constructor TSprite.Create;
begin
  inherited Create;
  actions := TList.Create;
end;


end.
