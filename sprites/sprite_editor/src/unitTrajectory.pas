unit unitTrajectory;

interface

uses classes;

type
  TTrajectory = class(TObject)
  private
    { Private declarations }
  public
    { Public declarations }
    points: TList;
    caption: string;
    trigger:  String;
    nexttraj:  String;
    width, height: integer;
    constructor Create(ncaption: String);
  end;

implementation

constructor TTrajectory.Create(ncaption: String);
begin
  inherited Create;
  caption := ncaption;
  points := TList.Create;
  trigger:='';
  nexttraj := '';
end;


end.
