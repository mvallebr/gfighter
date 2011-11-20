unit unitAction;

interface

uses classes;

type
  TAction = class(TObject)
  private
    { Private declarations }
  public
    { Public declarations }
    frames:     TList;
    caption:    String;
    nextAction: String;
    soundfile:  String;
    trigger:    String;
    constructor Create(ncaption: string);
  end;


implementation

constructor TAction.Create(ncaption: string);
begin
  inherited Create;
  caption := ncaption;
  frames := TList.Create;
  soundfile := '';
  nextAction := '';
end;

end.
