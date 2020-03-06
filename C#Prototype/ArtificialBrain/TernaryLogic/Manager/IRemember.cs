namespace TernaryLogic.Manager
{
    public interface IRemember
    {
        string Save();
        void Load(string state);
    }
}
