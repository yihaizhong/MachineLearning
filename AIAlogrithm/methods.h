#ifndef METHODS_H
#define METHODS_H

/**
 * @brief provided rand method
 */
class Methods
{
public:
	Methods()=delete;
	~Methods()=delete;
    /**
	 * @brief get a random number:[rmin,rmax]
     * @param rmin minimum number
     * @param rmax maximum number
     * @return a random number
     */
	static int randIn(int rmin, int rmax);
    /**
	 * @brief the same of above
	 */
	static double randIn(double rmin, double rmax);
	template<typename Edit,typename T>
	static bool textToNumber(Edit &line_edit, T *rel);
private:
	
};
template<typename Edit, typename T>
inline bool Methods::textToNumber(Edit &line_edit, T *rel)
{
	bool ok;
	*rel = (T)line_edit.text().toDouble(&ok);
	return ok;
}
#endif // METHODS_H
