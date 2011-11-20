unit unitInput;

interface

type
  TInput = class(TObject)
  private
    { Private declarations }
  public
    { Public declarations }
    caption: String;
    trigger: String;
    trigger2: String;
    props: array[1..10,1..16] of string;
    constructor Create(ncaption: String);
  end;

implementation


constructor TInput.Create(ncaption: String);
var
  i, j: integer;
begin
  inherited Create;
  caption := ncaption;
  for i := 1 to 10 do
    for j := 1 to 16 do
      props[i,j]:='';
  trigger := '';
  trigger2 := '';
end;


end.
