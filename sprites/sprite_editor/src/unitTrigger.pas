unit unitTrigger;


interface

uses classes, types, QExtCtrls;

type
  TTrigger = class(TObject)
  private
    { Private declarations }
  public
    { Public declarations }
    caption: string;
    text  : string;
    constructor Create(ncaption: String);
  end;

implementation

constructor TTrigger.Create(ncaption: String);
begin
  inherited Create;
  caption := ncaption;
  text := 'function OnTrigger(data)#13#10';
  text := text + 'result = data;'#13#10;
	text := text + 'result.pcurrent_action = "Action1";'#13#10;	text := text + 'return result;'#13#10;  text := text + 'end';
end;


end.
