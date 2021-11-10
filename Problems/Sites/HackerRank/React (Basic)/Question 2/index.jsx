import React from 'react';

function Articles({articles, field}) {
	let sortedArticles = [...articles]
	sortedArticles.sort((elem1, elem2) => {
		if ( elem1[field] < elem2[field] ){
			return 1;
		}
		if ( elem1[field] > elem2[field] ){
			return -1;
		}
		return 0;
	})

    return (
        <div className="card w-50 mx-auto">
            <table>
                <thead>
                <tr>
                    <th>Title</th>
                    <th>Upvotes</th>
                    <th>Date</th>
                </tr>
                </thead>
                <tbody>
                  	{sortedArticles.map((article, idx) => (
						<tr key={idx} data-testid="article" key="article-index">
							<td data-testid="article-title">{article.title}</td>
							<td data-testid="article-upvotes">{article.upvotes}</td>
							<td data-testid="article-date">{article.date}</td>
						</tr>
					))}
                </tbody>
            </table>
        </div>
    );

}

export default Articles;
